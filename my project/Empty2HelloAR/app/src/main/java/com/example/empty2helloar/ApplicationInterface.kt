package com.example.empty2helloar

object ApplicationInterface{
    external fun createApplication() : Long

    init {
        System.loadLibrary("Application.so")
    }
}


