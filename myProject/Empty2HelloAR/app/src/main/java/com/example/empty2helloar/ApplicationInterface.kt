package com.example.empty2helloar

import android.content.res.AssetManager

object ApplicationInterface{
    init {
        System.loadLibrary("native_lib")
    }

    external fun createApplication(manager : AssetManager) : Long
    external fun deleteApplication(application: Long)


}


