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
#include <openssl/md5.h>
#include <nan.h>
using namespace v8;

NAN_METHOD(CalculateLeblancMD5)
{
}

NAN_MODULE_INIT(Init)
{
    Nan::Set(target, Nan::New<String>("calculate").ToLocalChecked(),
            Nan::GetFunction(Nan::New<FunctionTemplate>(CalculateLeblancMD5)).ToLocalChecked());
}

NODE_MODULE(leblanc, Init);
