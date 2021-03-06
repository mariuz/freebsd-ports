# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	mixxx
PORTVERSION=	1.11.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://downloads.mixxx.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJ mixing application

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libmad.so:${PORTSDIR}/audio/libmad \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libtag.so:${PORTSDIR}/audio/taglib \
		libprotobuf.so:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		scons iconv
USE_QT4=	corelib gui network opengl script sql svg xml \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glu
MAKE_ARGS=	qtdir="${QT_PREFIX}" optimize=0
LATE_INSTALL_ARGS=	--install-sandbox=${STAGEDIR}

OPTIONS_DEFINE=		DOCS FAAD GPERFTOOLS LAME SHOUTCAST WAVPACK
OPTIONS_DEFAULT=	FAAD SHOUTCAST WAVPACK
OPTIONS_SUB=		yes

FAAD_LIB_DEPENDS=	libfaad.so:${PORTSDIR}/audio/faad \
			libmp4v2.so:${PORTSDIR}/multimedia/mp4v2
FAAD_MAKE_ARGS=		faad=1
FAAD_MAKE_ARGS_OFF=	faad=0
GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:${PORTSDIR}/devel/google-perftools
GPERFTOOLS_MAKE_ARGS=	perftools=1
GPERFTOOLS_MAKE_ARGS_OFF=	perftools=0
LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame
SHOUTCAST_LIB_DEPENDS=	libshout.so:${PORTSDIR}/audio/libshout
SHOUTCAST_MAKE_ARGS=	shoutcast=1
SHOUTCAST_MAKE_ARGS_OFF=	shoutcast=0
WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_MAKE_ARGS=	wv=1
WAVPACK_MAKE_ARGS_OFF=	wv=0

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/build/depends.py
	@${REINPLACE_CMD} -e "s|bzr |true |g" \
		${WRKSRC}/build/util.py
	@${REINPLACE_CMD} -e "/('install', docs)/d" \
		${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e "s|^Exec=.*|Exec=mixxx| ; \
		 s|^Icon=.*|Icon=${PREFIX}/share/pixmaps/mixxx-icon.png|" \
		${WRKSRC}/src/mixxx.desktop
.for i in midi/midimessage.h qtscript-bytearray/bytearrayclass.h
	@${ECHO_CMD} >> ${WRKSRC}/src/controllers/${i}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mixxx
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mixxx/plugins/soundsource
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in Mixxx-Manual.pdf README README.macro
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/HID
.for i in *.odt *.pdf
	(cd ${WRKSRC}/doc/HID && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR}/doc/HID)
.endfor

.include <bsd.port.mk>
