
package com.longtugame.jiumiao;

import org.CrossApp.lib.Cocos2dxActivity;
import org.CrossApp.lib.Cocos2dxGLSurfaceView;

import com.alipay.sdk.pay.H5Pay;
import com.alipay.sdk.pay.Pay;
import com.umeng.AnalyticsHome;

import android.os.Bundle;

public class Demo extends Cocos2dxActivity{
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		AnalyticsHome.init(this);
		Pay.init(this);
		H5Pay.init(this);
	}

    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// Demo should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }

    static {
        System.loadLibrary("CrossApp_cpp");
    }     
}
