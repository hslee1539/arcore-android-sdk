//
// Created by hs-mac on 2020/08/04.
//

#pragma once

namespace Empty2HelloAR{
    namespace Log{
        namespace Dependencies{
            #include <arcore_c_api.h>
            #include <android/log.h>

            inline void check(bool condition, const char *message){
                if(condition){
                    __android_log_print(ANDROID_LOG_ERROR, "Empty2HelloAr", "native-%s", message);
                }
            }
            inline void filterSuccess(ArStatus arResult, const char *message){
                if(arResult != AR_SUCCESS){
                    __android_log_print(ANDROID_LOG_ERROR, "Empty2HelloAr", "native-%s");
                }
            }
            template <typename t>
            inline void filterNoneZero(t target, const char *message){
                if (target == 0){
                    __android_log_print(ANDROID_LOG_ERROR, "Empty2HelloAr", "native-%s");
                }
            }
        }

        inline void check(bool condition, const char *message){
            Dependencies::check(condition, message);
        }
        inline void filterSuccess(ArStatus arResult, const char *message){
            Dependencies::filterSuccess(arResult, message);
        }
        template <typename t>
        inline void filterNoneZero(t target, const char *message){
            Dependencies::filterNoneZero(target, message);
        }
    }
}