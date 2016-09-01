/*
 * =====================================================================================
 *
 *       Filename:  leblanc.cpp
 *
 *    Description:  Calculate file checksum using MD5 in node.js native (start with reading a file).
 *
 *        Version:  1.0
 *        Created:  2016/08/10 17时41分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  XadillaX (zkd), i@2333.moe
 *   Organization:  Design & Development Center, Souche Inc. CHINA
 *
 * =====================================================================================
 */
#include "calculate.h"
#include <nan.h>
#include <string>
using namespace std;
using namespace v8;

class CalculateLeblancMD5Worker : public Nan::AsyncWorker {
public:
    CalculateLeblancMD5Worker(Nan::Callback* callback, string filename) :
            AsyncWorker(callback),
            filename(filename),
            err("")
    {
    }

    ~CalculateLeblancMD5Worker()
    {
    }

    void Execute()
    {
        try {
            err = RealCalculateLeblancMD5(filename.c_str(), md5);
        } catch(...) {
            err = "unknown error in `RealCalculateLeblancMD5`.";
        }
    }

    void HandleOKCallback()
    {
        Nan::HandleScope scope;

        if(err.size())
        {
            Local<Value> argv[] = { Nan::Error(err.c_str()) };
            callback->Call(1, argv);
            return;
        }

        Local<Value> argv[] = {
            Nan::Undefined(),
            Nan::New<String>(md5).ToLocalChecked()
        };
        callback->Call(2, argv);
        return;
    }

private:
    string filename;
    string err;
    char md5[33];
};

NAN_METHOD(CalculateLeblancMD5)
{
    if(!info.Length())
    {
        return Nan::ThrowError("bad arguments");
    }

    if(info.Length() == 1 || info[1]->IsUndefined() || info[1]->IsNull())
    {
        // calculate it sync

        String::Utf8Value filename(info[0]->ToString());

        char md5[33];
        string err;
        try {
            err = RealCalculateLeblancMD5(*filename, md5);
        } catch(...) {
            return Nan::ThrowError("unknown error in `RealCalculateLeblancMD5`.");
        }

        if(err.size() == 0)
        {
            info.GetReturnValue().Set(Nan::New<String>(md5).ToLocalChecked());
            return;
        }

        return Nan::ThrowError(err.c_str());
    }

    // calculate it async
    String::Utf8Value filename(info[0]->ToString());
    Nan::Callback* cb = new Nan::Callback(info[1].As<Function>());
    AsyncQueueWorker(new CalculateLeblancMD5Worker(cb, *filename));
}

NAN_MODULE_INIT(Init)
{
    Nan::Set(target, Nan::New<String>("calculate").ToLocalChecked(),
            Nan::GetFunction(Nan::New<FunctionTemplate>(CalculateLeblancMD5)).ToLocalChecked());
}

NODE_MODULE(leblanc, Init);
