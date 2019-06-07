#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QWindow>
#include "../app/datareceiver.h"
#include "../app/token.h"
#include "../app/vk.h"
#include "../app/postloader.h"

using namespace testing;

/** MODULE VK
 * BEGIN
 */

/* Auth tests */

TEST(auth, loadLoginDataTest) {
    VK vk;
    Token *token = vk.getTokenFromFile();
    EXPECT_NE(token, nullptr);
}

TEST(auth, haveAccessTest) {
    VK vk;
    Token *token = vk.getTokenFromFile();
    EXPECT_STREQ(vk.checkAccess(token).toStdString().c_str(), NO_ERR.toStdString().c_str());
}


TEST(auth, accessDeniedTest) {
    QFile file("data");
    file.open(QFile::ReadWrite);
    file.copy("backup");
    VK vk;
    Token *token = new Token;
    token->setValue("123abc");
    vk.setToken(token);
    vk.saveToken();
    QString result = vk.checkAccess(token);
    file.remove();
    QFile backup("backup");
    backup.rename("data");
    EXPECT_STREQ(result.toStdString().c_str(), AT_ERR.toStdString().c_str());
}

TEST(auth, logoutTest) {
    VK vk;
    QFile file("data");
    file.copy("backup");
    bool result = vk.logout(new QWindow());
    QFile backup("backup");
    file.remove();
    backup.rename("data");
    EXPECT_TRUE(result);
}

/* Utils tests */

TEST(utils, currentTokenTest) {
    VK vk;
    Token *token = new Token;
    token->setValue("123abc");
    vk.setToken(token);
    token = vk.getToken();
    EXPECT_STREQ(token->getValue().toStdString().c_str(), "123abc");
}

TEST(utils, saveTokenTest) {
    VK vk;
    Token *token = new Token;
    token->setValue("123abc");
    QFile file("data");
    file.open(QFile::ReadWrite);
    file.copy("backup");

    vk.setToken(token);
    vk.saveToken();

    token = vk.getTokenFromFile();
    QFile backup("backup");
    file.remove();
    backup.rename("data");
    EXPECT_STREQ(token->getValue().toStdString().c_str(), "123abc");
}

/** MODULE VK
 * END
 */

/** MODULE DATARECEIVER
 * BEGIN
 */

/* Data receive tests */

TEST(dr, setSourceToReceive) {
    DataReceiver receiver;
    receiver.setUrl("https://www.google.ru");
    EXPECT_STRNE(receiver.getUrl().toStdString().c_str(), "");
}

TEST(dr, getData) {
    DataReceiver receiver;
    VK vk;
    receiver.setUrl("https://api.vk.com/method/users.get?access_token=" + vk.getTokenFromFile()->getValue() + "&v=5.52");
    EXPECT_STRNE(receiver.getData().toStdString().c_str(), "");
}

/** MODULE DATARECEIVER
 * END
 */

/** MODULE DATALOADER
 * BEGIN
 */

/* Data loading tests */

TEST(dl, loadData) {
    PostLoader loader;
    loader.getPosts(0);
    loader.thread->terminate();
    EXPECT_TRUE(loader.thread->isRunning());
}

TEST(dl, setData) {
    PostLoader loader;
    loader.getPosts(0);
    loader.thread->terminate();
    EXPECT_NE(loader.getData(), nullptr);
}

/** MODULE DATALOADER
 * END
 */

/** MODULE THREADS
 * BEGIN
 */

/* Testing threads */

TEST(threads, endOfFeedException) {
    PostLoader loader;
    loader.getPosts(10000000);
    loader.thread->run();
    EXPECT_TRUE(loader.thread->isEndOfFeed());
}

/** MODULE THREADS
 * END
 */
