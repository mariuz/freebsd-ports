--- ./base/debug/stack_trace_posix.cc.orig	2014-08-20 21:02:42.000000000 +0200
+++ ./base/debug/stack_trace_posix.cc	2014-08-22 15:06:24.000000000 +0200
@@ -590,6 +590,10 @@
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if defined(OS_FREEBSD)
+    // TODO (rene) avoid link error, implement something?
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -605,6 +609,7 @@
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
