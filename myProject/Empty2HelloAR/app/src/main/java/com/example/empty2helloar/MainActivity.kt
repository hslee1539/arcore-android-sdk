package com.example.empty2helloar

import android.content.res.AssetManager
import android.opengl.GLES20
import android.opengl.GLSurfaceView
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MainActivity : AppCompatActivity() ,GLSurfaceView.Renderer{
    private var viewportWidth : Int = 0
    private var viewportHeight : Int = 0
    private var viewportChange : Boolean = false
    private var application: Long = 0


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Set up renderer.
        surfaceview.apply{
            preserveEGLContextOnPause = true
            setEGLContextClientVersion(2)
            setEGLConfigChooser(8,8,8,8,16,0)
            setRenderer(this@MainActivity)
            renderMode = GLSurfaceView.RENDERMODE_CONTINUOUSLY
            setWillNotDraw(false)
        }
        application = ApplicationInterface.createApplication(assets)

    }

    override fun onDestroy() {
        super.onDestroy()
        ApplicationInterface.deleteApplication(this.application)
    }

    override fun onResume() {
        super.onResume()
        surfaceview.onResume()
        if(!PermissionHelper.hasCameraPermission(this))
            PermissionHelper.requestCameraPermission(this)

    }

    override fun onPause() {
        super.onPause()
        surfaceview.onPause()
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

    override fun onDrawFrame(gl: GL10?) {
        //TODO("Not yet implemented")
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        this.viewportWidth = width
        this.viewportHeight = height
        this.viewportChange = true
    }

    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        GLES20.glClearColor(0.1f, 0.1f, 0.1f, 1.0f)
        //TODO("Not yet implemented")
    }
}