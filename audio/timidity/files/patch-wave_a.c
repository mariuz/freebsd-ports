--- ./wave_a.c.orig	1996-05-20 08:10:15.000000000 -0500
+++ ./wave_a.c	2013-04-21 10:18:23.000000000 -0500
@@ -35,6 +35,7 @@
 
 #ifdef __FreeBSD__
 #include <stdio.h>
+#include <string.h>
 #endif
 
 #include "config.h"
