--- ./third_party/webrtc/base/httpcommon.cc.orig	2014-08-20 21:04:28.000000000 +0200
+++ ./third_party/webrtc/base/httpcommon.cc	2014-08-22 18:44:03.000000000 +0200
@@ -382,7 +382,7 @@
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(BSD)
+#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
   tm *tm_for_timezone = localtime((time_t *)&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
