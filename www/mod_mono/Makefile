# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	mod_mono
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Apache module for serving ASP.NET applications

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		xsp:${PORTSDIR}/www/xsp
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		xsp:${PORTSDIR}/www/xsp

USES=		libtool:oldver mono pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_APACHE=	22
CONFIGURE_ARGS=	--man=${PREFIX}/man
INSTALL_TARGET=	install

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 13
MOD_MONOCONFDIR=${APACHEETCDIR}
.else
MOD_MONOCONFDIR=${APACHEETCDIR}/Includes
.endif

PLIST_SUB+=	MOD_MONOCONFDIR=${MOD_MONOCONFDIR}

post-patch:
	@${REINPLACE_CMD} 's|%%MOD_MONOCONFDIR%%|${PREFIX}/${MOD_MONOCONFDIR}|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
