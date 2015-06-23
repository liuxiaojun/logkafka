///////////////////////////////////////////////////////////////////////////
//
// logkafka - Collect logs and send lines to Apache Kafka v0.8+
//
///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2015 Qihoo 360 Technology Co., Ltd. All rights reserved.
//
// Licensed under the MIT License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////
#ifndef LOGKAFKA_SIGNAL_HANDLER_H_
#define LOGKAFKA_SIGNAL_HANDLER_H_

#include <signal.h>

#include <cstdlib>
#include <cstring>
#include <string>

#include "base/tools.h"

#include "easylogging/easylogging++.h"

#include <uv.h>

using namespace std;

namespace logkafka {

typedef void (*SignalFunc)(void *);

class SignalHandler
{
    public:
        SignalHandler() {};
        bool init(uv_loop_t *loop,
                int signum,
                void *signal_func_arg,
                SignalFunc on_signal);

    private:
        static void default_cb(uv_signal_t* handle, int signum);
        SignalFunc m_signal_func;
        void *m_signal_func_arg;
        uv_signal_t m_handle;
};

} // namespace logkafka

#endif // LOGKAFKA_SIGNAL_HANDLER_H_
