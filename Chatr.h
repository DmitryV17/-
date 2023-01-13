#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Message.h"

struct UserLoginExp : public std::exception
{
	const char* what() const noexcept override { return "error: user login is busy"; }
};

struct UserNameExp : public std::exception
{
	const char* what() const noexcept override { return "error: user name is busy"; }
};

class Chat {
	bool isChatWork_ = false;
	std::vector<User> userList_;
	std::vector<Message> messageList_;
	std::shared_ptr<User> currentUser_ = nullptr;

	void login();
	void signUp();
	void showChat() const;
	void showAllUsersName() const;
	void addMessage();
	std::vector<User>& getAllUsers() { return userList_; }
	std::vector<Message>& getAllMessage() { return messageList_; }
	std::shared_ptr<User>& getUserByLogin(const std::stringbuf& login) const;
	std::shared_ptr<User>& getUserByName(const std::stringbuf& name) const;

public:
	void start();
	bool isChatWork() const { return isChatWork_; }
	std::shared_ptr<User> getCurrentUser() const { return currentUser_; }
	void showLoginMenu();
	void showUserMenu();
};