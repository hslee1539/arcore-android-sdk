package com.example.empty2helloar

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    override fun onResume() {
        super.onResume()
        if(!PermissionHelper.hasCameraPermission(this))
            PermissionHelper.requestCameraPermission(this)
    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if(!PermissionHelper.hasCameraPermission(this))
            if(!PermissionHelper.shouldShowRequestPermissionRationale(this))
                PermissionHelper.launchPermissionSettings(this)
    }
}