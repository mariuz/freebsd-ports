# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/pydbus-common/Makefile 19685 2014-05-25 13:11:28Z kwm $

PORTNAME=	dbus
PORTVERSION=	1.1.1
PORTREVISION?=	4
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX?=	py
PKGNAMESUFFIX?=	-common
DISTNAME=	dbus-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Common files for the Python bindings for the D-BUS messaging system

BUILD_DEPENDS=	dbus-glib>=0:${PORTSDIR}/devel/dbus-glib

SLAVE_PORT?=	no

USES=		gettext gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--disable-api-docs
INSTALL_TARGET=	install-strip

.if ${SLAVE_PORT} == no
USE_PYTHON_BUILD=	2

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	HTMLDOCS
HTMLDOCS_DESC=	build html documentation
HTMLDOCS_CONFIGURE_OFF=	--disable-html-docs
HTMLDOCS_BUILD_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|HEADERS install-dist_docDATA|HEADERS|g ; \
		s|PYTHON install-nodist_docDATA|PYTHON|g' \
			${WRKSRC}/Makefile.in
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/dbus-1.0/dbus/
	${INSTALL_DATA} ${WRKSRC}/include/dbus-python.h \
		${STAGEDIR}${PREFIX}/include/dbus-1.0/dbus/dbus-python.h
	${INSTALL_DATA} ${WRKSRC}/dbus-python.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dbus-python.pc

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.if ${PORT_OPTIONS:MHTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
.endif
.else # slave is defined
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=	pydbus-common>=0:${PORTSDIR}/devel/pydbus-common
USE_LDCONFIG=	yes
.if ${SLAVE_PORT} == python2
USE_PYTHON=	2
.endif
.if ${SLAVE_PORT} == python3
USE_PYTHON=	3
.endif

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/dbus-1.0 \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dbus-python.pc
	@${RM} -fr ${STAGEDIR}/${DOCSDIR}
.endif # end of slaving block

.include <bsd.port.mk>
