//
// Created by hs-mac on 2020/08/03.
//

#include "Application.h"

inline Emtpy2HelloAR::Application *toAppPointer(jlong ptr){
    return reinterpret_cast<Emtpy2HelloAR::Application *>(ptr);
}


Emtpy2HelloAR::Application::Application(AAssetManager *assetManager) : assetManager(assetManager) {

}

Emtpy2HelloAR::Application::~Application() {
    if(this->session != nullptr)
        ArSession_destroy(this->session);
    if(this->frame != nullptr)
        ArFrame_destroy(this->frame);
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_example_empty2helloar_ApplicationInterface_createApplication(JNIEnv* env,jobject thiz,
                                                                      jobject manager){
    auto pManager = AAssetManager_fromJava(env, manager);
    return reinterpret_cast<intptr_t>(new Emtpy2HelloAR::Application(pManager));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_empty2helloar_ApplicationInterface_deleteApplication(JNIEnv *env, jobject thiz,
                                                                      jlong application) {
    delete toAppPointer(application);
}