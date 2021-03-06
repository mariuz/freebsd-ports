# $FreeBSD$

PORTNAME=	tagutil
PORTVERSION=	3.0.1
CATEGORIES=	audio

MAINTAINER=	alex@kaworu.ch
COMMENT=	Command line interface tool to manage tags in music files

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libyaml.so:${PORTSDIR}/textproc/libyaml

USE_GITHUB=	yes
GH_ACCOUNT=	kAworu
GH_TAGNAME=	v3.0.1
GH_COMMIT=	b7ce91f

USES=		pkgconfig cmake iconv
PLIST_FILES=	bin/tagutil \
		man/man1/tagutil.1.gz

CMAKE_ARGS=	-DMAN_PATH=${PREFIX}/man

OPTIONS_DEFINE=	JSON
OPTIONS_MULTI=	MEDIA
OPTIONS_MULTI_MEDIA=	FLAC OGG TAGLIB
OPTIONS_DEFAULT=	FLAC OGG TAGLIB
TAGLIB_DESC=	Multiple file format but limited tags support
JSON_DESC=	JSON output format support

JSON_LIB_DEPENDS+=	libjansson.so:${PORTSDIR}/devel/jansson
JSON_CMAKE_OFF+=	-DWITHOUT_JSON=yes
FLAC_LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CMAKE_OFF+=	-DWITHOUT_FLAC=yes
OGG_LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
OGG_CMAKE_OFF+=	-DWITHOUT_OGGVORBIS=yes
TAGLIB_LIB_DEPENDS+=	libtag_c.so:${PORTSDIR}/audio/taglib
TAGLIB_CMAKE_OFF+=	-DWITHOUT_TAGLIB=yes

.include <bsd.port.mk>
