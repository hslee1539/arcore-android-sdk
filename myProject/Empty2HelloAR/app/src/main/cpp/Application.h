//
// Created by hs-mac on 2020/08/03.
//

#pragma once
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <jni.h>
#include "arcore_c_api.h"
#include "Log.h"

namespace Empty2HelloAR{
    class Application{
    private:
        ArSession* session = nullptr;
        ArFrame* frame = nullptr;
        AAssetManager* const assetManager;

        bool isInstallCoreApk = false;

    public:
        explicit Application(AAssetManager *assetManager);
        ~Application();

        // OnPause is called on the UI thread from the Activity's onPause method.
        void OnPause();

        // OnResume is called on the UI thread from the Activity's onResume method.
        void OnResume(void* env, void* context, void* activity);
//
        //// OnSurfaceCreated is called on the OpenGL thread when GLSurfaceView
        //// is created.
        //void OnSurfaceCreated();
//
        //// OnDisplayGeometryChanged is called on the OpenGL thread when the
        //// render surface size or display rotation changes.
        ////
        //// @param display_rotation: current display rotation.
        //// @param width: width of the changed surface view.
        //// @param height: height of the changed surface view.
        //void OnDisplayGeometryChanged(int display_rotation, int width, int height);
//
        //// OnDrawFrame is called on the OpenGL thread to render the next frame.
        //void OnDrawFrame(bool depthColorVisualizationEnabled,
        //                 bool useDepthForOcclusion);


    };
}