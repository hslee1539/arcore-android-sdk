package com.example.empty2helloar

import android.content.res.AssetManager

object ApplicationInterface{
    external fun createApplication(manager : AssetManager) : Long
    external fun deleteApplication(application: Long)

    init {
        System.loadLibrary("Application.so")
    }
}


