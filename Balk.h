#ifndef BALK_H
#define BALK_H


//class Balk
//{
//public:
//    Balk();
//};



#pragma once

#include "ResponseHandler.h"
#include <iostream>
#include <cassert>
#include <chrono>
#include <fstream>
#include <vector>

class CommandHandlerImpl;

class CommandHandler {
public:
    explicit CommandHandler(size_t max_block_size);
    ~CommandHandler();

    void HandleCommand(const std::string& command);
    void Stop();

    void AddResponseHandler(std::shared_ptr<ResponseHandler> handler);
    void ResetResponseHandlers();

private:
    std::shared_ptr<CommandHandlerImpl> impl_;
};


#endif // BALK_H
