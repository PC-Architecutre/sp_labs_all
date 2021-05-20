#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>

MODULE_AUTHOR("TEAM1");
MODULE_DESCRIPTION("Lab 2, using struct list_head");
MODULE_LICENSE("MIT");

#define LIST_LEN 12
#define MSG_PREF "TEAM1"

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);

typedef struct {
        struct list_head lnode;
        uint32_t val;
} int_node_t;

// макрос для освобождения памяти выделеной под элементы списка,
// do {}while(0) требуеться, чтоб обернуть код макроса в блок, простого {} недостаточно
#define ilfree(list_head) \
    do {                                                                 \
        int_node_t *__ptr, *__tmp;                                       \
        list_for_each_entry_safe(__ptr, __tmp, (list_head), lnode) {     \
            kfree(__ptr);                                                \
        }                                                                \
    } while(0)

// макрос для вывода значений списка в консоль
#define ilprint(list_head) \
    do {                                                                 \
        int_node_t *__ptr;                                               \
        print_msg("List: {");                                            \
        list_for_each_entry(__ptr, (list_head), lnode) {                 \
            printk(KERN_ERR "\t%i ", __ptr->val);                        \
        }                                                                \
        printk(KERN_ERR "}\n");                                          \
    } while(0)

// инициализация головы списка, всю реализацию списка можно найти по ссылке https://elixir.bootlin.com/linux/latest/source/include/linux/list.h#L714
static struct list_head int_list = LIST_HEAD_INIT(int_list);

// функция которая побитово сдвигает значение каждого элемента списка на 1 влево
static void task(void) {
        int_node_t *ptr;
        printk(KERN_ERR "\t%s ", "Making conjunction");
        int k = -1;
        list_for_each_entry(ptr, &int_list, lnode) {

                k &= ptr->val;
                printk(KERN_ERR "\t%i ", k);
        }
}

static int __init list_module_init(void)
{
        int i;
        int ret = 0;
        print_msg("List allocation start...\n");
        // выделяем динамически память для элементов списка в цыкле
        for (i = 0; i < LIST_LEN; ++i) {
                int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr), GFP_KERNEL);
                if (!ptr) {
                        print_msg("Can't alloc memory\n");
                        ret = -ENOMEM;
                        goto alloc_err;
                }
                // функция которая дает нам рандомное значение для указанного количества байт
                get_random_bytes(&ptr->val, sizeof(ptr->val));
                list_add_tail(&ptr->lnode, &int_list);
        }
        print_msg("List allocation finish\n");
        ilprint(&int_list);

        task();

        ilprint(&int_list);

        return 0;
alloc_err:
        ilfree(&int_list);
        return ret;
}

static void __exit list_module_exit(void)
{
        ilfree(&int_list);
        print_msg("Hasta la vista, Kernel!\n");
}
module_init(list_module_init);
module_exit(list_module_exit);

