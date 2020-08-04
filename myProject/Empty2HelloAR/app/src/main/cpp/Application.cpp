//
// Created by hs-mac on 2020/08/03.
//

#include "Application.h"

namespace Empty2HelloAR{
    inline Application *toApplication(jlong ptr){
        return reinterpret_cast<Application *>(ptr);
    }

    Application::Application(AAssetManager *assetManager) : assetManager(assetManager) {
    }

    Application::~Application() {
        if(this->session != nullptr)
            ArSession_destroy(this->session);
        if(this->frame != nullptr)
            ArFrame_destroy(this->frame);
    }

    void Application::OnPause() {
        if(this->session != nullptr)
            ArSession_pause(this->session);

    }

    void Application::OnResume(void *env, void *context, void *activity) {
        if(this->session == nullptr){
            ArInstallStatus arInstallStatus;
            // install 이 설치가 false면 설치할 수 있게 1 반대면 0
            auto isNeededInstall = int32_t(!this->isInstallCoreApk);

            // resume이 됬을 때 다시 에러가 아닌 이상 AR_INSTALL_STATUS_INSTALL_REQUESTED를 반환.
            // application must handle these cases at least somewhat gracefully.??
            Log::filterSuccess(
                    ArCoreApk_requestInstall(env, activity, isNeededInstall, &arInstallStatus),
                    "OnResume/ArCoreApk_requestInstall");

            switch (arInstallStatus) {
                case AR_INSTALL_STATUS_INSTALLED:
                    break;
                case AR_INSTALL_STATUS_INSTALL_REQUESTED:
                    this->isInstallCoreApk = true;
                    return;
            }

            Log::filterSuccess(
                    ArSession_create(env, context, &this->session),
                    "OnResume/ArSession_create"
                    );
            Log::filterNoneZero(this->session, "OnResume/ArSession_create");


        }
    }
}

namespace KotlinInterface{
    using namespace Empty2HelloAR;
    extern "C" JNIEXPORT jlong JNICALL
    Java_com_example_empty2helloar_ApplicationInterface_createApplication(JNIEnv* env,jobject thiz,
                                                                          jobject manager){
        auto pManager = AAssetManager_fromJava(env, manager);
        return reinterpret_cast<intptr_t>(new Application(pManager));
    }

    extern "C"
    JNIEXPORT void JNICALL
    Java_com_example_empty2helloar_ApplicationInterface_deleteApplication(JNIEnv *env, jobject thiz,
                                                                          jlong application) {
        delete toApplication(application);
    }

    extern "C" JNIEXPORT void JNICALL
    Java_com_example_empty2helloar_ApplicationInterface_OnPause(JNIEnv *env, jobject thiz,
                                                                jlong application){
        toApplication(application)->OnPause();
    }
    extern "C" JNIEXPORT void JNICALL
    Java_com_example_empty2helloar_ApplicationInterface_OnResume(JNIEnv *env, jobject thiz,
                                                                 jlong application, jobject context,
                                                                 jobject activity) {
        toApplication(application)->OnResume(env, context, activity);
    }

}



