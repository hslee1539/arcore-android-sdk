package com.example.empty2helloar

import android.Manifest
import android.app.Activity
import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import android.provider.Settings
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat

class PermissionHelper{
    companion object{
        val CAMERA_PERMISSION_CODE = 0

        fun hasCameraPermission(activity: Activity): Boolean {
            return ContextCompat.checkSelfPermission(activity, Manifest.permission.CAMERA) ==
                    PackageManager.PERMISSION_GRANTED
        }

        fun requestCameraPermission(activity: Activity){
            return ActivityCompat.requestPermissions(activity, arrayOf(Manifest.permission.CAMERA),
                CAMERA_PERMISSION_CODE)
        }

        fun shouldShowRequestPermissionRationale(activity: Activity): Boolean {
            return ActivityCompat.shouldShowRequestPermissionRationale(activity,Manifest.permission.CAMERA)
        }

        fun launchPermissionSettings(activity: Activity){
            Intent().apply {
                setAction(Settings.ACTION_APPLICATION_DETAILS_SETTINGS)
                setData(Uri.fromParts("package", activity.getPackageName(), null))
                activity.startActivity(this)
            }
        }
    }
}