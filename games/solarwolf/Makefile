# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	solarwolf
PORTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.pygame.org/shredwheat/solarwolf/

MAINTAINER=	mail@maxlor.com
COMMENT=	Action/arcade game originally based of SolarFox on the Atari 2600

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	2

DESKTOP_ENTRIES=	"SolarWolf" "${COMMENT}" "solarwolf" \
	"solarwolf" "Game;ArcadeGame;" false

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/solarwolf
	(cd ${WRKSRC}; tar -cf - --exclude ".xvpics" --exclude "dist" .) | \
		(cd ${STAGEDIR}${PREFIX}/share/solarwolf; tar --unlink -xf -)
	${PRINTF} "#!/bin/sh\nexec ${PYTHON_CMD} ${PREFIX}/share/solarwolf/solarwolf.py\n" \
		> ${STAGEDIR}${PREFIX}/bin/solarwolf
	${CP} ${WRKSRC}/dist/solarwolf.6.gz ${STAGEDIR}${MAN6PREFIX}/man/man6/
	${CP} ${WRKSRC}/dist/solarwolf.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
