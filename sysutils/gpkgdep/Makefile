# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	gpkgdep
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Shows package dependencies in tree views

LICENSE=	GPLv2

USE_GNOME=	gtk20
USE_AUTOTOOLS=	automake14 autoconf
AUTOMAKE_ARGS=	--add-missing
USES=		gmake pkgconfig tar:bzip2
PLIST_FILES=	bin/gpkgdep

.include <bsd.port.mk>
