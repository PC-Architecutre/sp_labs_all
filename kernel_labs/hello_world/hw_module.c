#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("Team 1");  // указывается, кто написал модуль
MODULE_DESCRIPTION("Hello world kernel module"); // описание для человека, что делает модуль
MODULE_LICENSE("MIT"); // лицензия распространяется код

/*
В этом модуле определены две функции, одна вызывается, когда модуль загружается в
ядро (hello_init), другая, когда модуль удаляется (hello_exit). Строчки с module_init и
module_exit используют специальные макросы ядра, чтобы задать роль этих двух функций.
*/

static int __init hw_init(void)
{
	printk(KERN_ERR "Hello, Kernel!\n");
	return 0;
}

static void __exit hw_exit(void)
{
	printk(KERN_ERR "Hasta la vista, Kernel!\n");
}
module_init(hw_init);
module_exit(hw_exit);
