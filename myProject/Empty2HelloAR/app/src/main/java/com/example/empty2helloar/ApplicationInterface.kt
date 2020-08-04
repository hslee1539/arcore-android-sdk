package com.example.empty2helloar

import android.app.Activity
import android.content.Context
import android.content.res.AssetManager

object ApplicationInterface{
    init {
        System.loadLibrary("native_lib")
    }

    external fun createApplication(manager : AssetManager) : Long
    external fun deleteApplication(application: Long)
    external fun OnPause(application: Long)
    external fun OnResume(application: Long, context: Context, activity: Activity)


}


