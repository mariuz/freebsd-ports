# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	plib
PORTVERSION=	1.8.5
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable library for joystick/sound/OpenGL GUI/3D math

USES=		gmake
USE_XORG=	xt xi xmu xext x11
USE_GL=		glu
GNU_CONFIGURE=	yes

CXXFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-js-jsBSD.cxx

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||g ; \
		 s|-ldl||g ; \
		 s|-lc_r||g' ${WRKSRC}/configure
	@${ECHO} "JS component is not compiled with new usb stack"

post-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/plib-jscal ${FILESDIR}/jsBSDCal.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/plib-jscal ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
