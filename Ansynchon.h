#ifndef ANSYNCHON_H
#define ANSYNCHON_H


//class Ansynchon
//{
//public:
//    Ansynchon();
//};

#include <string>
#include "Balk.h"

namespace Ansynchon {

using ContextId = size_t;

void AddResponseHandler(std::shared_ptr<ResponseHandler> handler);

ContextId Connect(size_t block_size);

void Receive(const std::string& command, ContextId context_id);

void Disconnect(ContextId context_id);

void ResetResponseHandlers();
}


#endif // ANSYNCHON_H
