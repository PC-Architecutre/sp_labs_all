//
// Created by misha on 06.04.21.
//

#include "Parser.h"
#include <QString>

QJsonObject Parser::parse(QJsonObject request) {
    QJsonObject response;

    QJsonValue reqType = request[TYPE_VAL];


    if (reqType == GET_TEST_BY_ID_REQ)
    {
        response[STATUS] = true;
        response[TYPE_VAL] = GET_TEST_BY_ID_REQ;
        int id = request[ID].toInt();
        Test t = _tc->GetTestById(id);
        QJsonObject testJson;
        response[RESULT] = getTest(t);
        return response;
    }

    if (reqType == GET_ALL_TESTS_REQ)
    {
        response[STATUS] = true;
        response[TYPE_VAL] = GET_ALL_TESTS_REQ;
        auto tests = _tc->GetAllTests();
        QJsonArray testsJson;
        foreach(auto t, tests)
            {
                testsJson.push_back(getTest(t));
            }
        response[RESULT] = testsJson;
        return response;
    }

    if  (reqType == GET_USER_RES_REQ)
    {
        response[STATUS] = true;
        response[TYPE_VAL] = GET_USER_RES_REQ;
        User u;
        QJsonArray resultJson;
        u.SetId(request[ID].toInt());
        auto rez = _tc->GetUserResults(u);
                foreach(auto r, rez)
            {
                QJsonObject rJson;
                rJson[ID] = r.GetId();
                rJson[SCORE] = r.GetScore();
//                QJsonObject userJson;
//                userJson[NAME] = QString::fromStdString(r.GetUser().GetName());
//                rJson[USER] = userJson;
                rJson[TEST] = getTest(r.GetTest());
                resultJson.push_back(rJson);
            }
        response[RESULT] = resultJson;
        return response;
    }

     if (reqType == GET_RES_BY_TEST_ID_REQ)
     {
         response[STATUS] = true;
         QJsonArray resultJson;
         auto rez = _tc->GetResultsByTestId(request[TEST_ID].toInt());
         foreach(auto r, rez)
             {
                QJsonObject rJson;
                rJson[ID] = r.GetId();
                rJson[SCORE] = r.GetScore();
                QJsonObject userJson;
                userJson[ID] = r.GetUser().GetId();
                userJson[NAME] = QString::fromStdString(r.GetUser().GetName());
                rJson[USER] = userJson;
                rJson[TEST] = getTest(r.GetTest());
                resultJson.push_back(rJson);
             }
            response[RESULT] = resultJson;
         return response;
     }

     if (reqType == GET_USER_BY_NAME_REQ)
     {
         auto user = _tc->GetUserByName(request[NAME].toString());
         response[TYPE_VAL] = GET_USER_BY_NAME_REQ;
         if (user == nullptr)
         {
             response[STATUS] = false;
             return response;
         }
         QJsonObject userJson;
         userJson[ID] = user->GetId();
         userJson[NAME] = QString::fromStdString(user->GetName());
         response[RESULT] = true;
         response[RESULT] = userJson;
         return response;
     }

     if (reqType == SAVE_USER_RES_REQ)
     {
         TestResult tr;
         tr.SetId(request[ID].toInt());
         tr.SetScore(request[SCORE].toInt());
         User* user = new User();
         QJsonValue uu = request[USER];
         user->SetId(uu[ID].toInt());
         user->SetName(uu[NAME].toString().toStdString());
         tr.SetUser(user);
         Test* test = new Test();
         QJsonValue tt = request[TEST];
         test->SetId(tt[ID].toInt());
         tr.SetTest(test);
         _tc->SaveUserResult(tr);
         response[TYPE_VAL] = SAVE_USER_RES_REQ;
         response[STATUS]= true;
         return response;
     }
}

QJsonObject Parser::getTest(Test t)
{
    QJsonObject testJson;
    testJson[ID] = t.GetId();
    testJson[NAME] = QString::fromStdString(t.GetName());
    testJson[TIME_CONSTRAINT] = t.GetTimeConstraint();

    QJsonArray questionsJson;
            foreach(auto q, t.GetQuestions())
        {
            QJsonObject qJson;
            qJson[ID] = q.GetId();
            qJson[QUESTION_TEXT] = QString::fromStdString(q.GetQuestionText());
            qJson[IS_MULT_CHOICE] = q.IsMultipleChoice();
            qJson[POINTS] = q.GetPoints();
            QJsonArray questionOptionJson;
                    foreach(auto qo, q.GetOptions())
                {
                    QJsonObject qoJson;
                    qoJson[ID] = qo.GetId();
                    qoJson[TEXT] = QString::fromStdString(qo.GetText());
                    qoJson[IS_CORRECT] = qo.IsCorrect();
                    questionOptionJson.push_back(qoJson);
                }
            qJson[QUESTION_OPTIONS] = questionOptionJson;
            questionsJson.push_back(qJson);
        }
    testJson[QUESTIONS] = questionsJson;
    return testJson;
}

Parser::Parser(TestController* tc) {
    _tc = tc;
}
