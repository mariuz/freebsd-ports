# Created by: Stefan Schwarzer <sschwarzer@sschwarzer.net>
# $FreeBSD$

PORTNAME=	webware
DISTVERSION=	1.1.1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/Webware/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Webware-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile web application server written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mx-base>0:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	2
NO_BUILD=	yes

WEBWARE_USER?=	webkit
WEBWARE_GROUP?=	${WEBWARE_USER}
USERS=${WEBWARE_USER}
GROUPS=${WEBWARE_GROUP}
WEBWARE_MASTER_DIR?=${PREFIX}/share/webware
WEBKIT_HOME_DIR?=${PREFIX}/www/webkit
INSTALL_ENV=	PKG_PREFIX=${PREFIX} \
		PYTHON=${PYTHON_CMD} \
		LOCALBASE=${LOCALBASE} \
		WEBWARE_USER=${WEBWARE_USER} \
		WEBWARE_GROUP=${WEBWARE_GROUP} \
		WEBWARE_MASTER_DIR=${WEBWARE_MASTER_DIR} \
		WEBKIT_HOME_DIR=${WEBKIT_HOME_DIR}

PLIST_SUB+=	WEBWARE_MASTER_DIR=${WEBWARE_MASTER_DIR:S,^${PREFIX}/,,}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/sbin/apxs|${APXS}|' ${WRKSRC}/WebKit/Adapters/mod_webkit1/Makefile
	@${REINPLACE_CMD} -e 's|/usr/sbin/apxs|${APXS}|' ${WRKSRC}/WebKit/Adapters/mod_webkit2/Makefile
	@${RM} ${WRKSRC}/WebKit/Adapters/mod_webkit2/Makefile.bak
	@${RM} ${WRKSRC}/WebKit/Adapters/mod_webkit1/Makefile.bak

do-install:
	@${MKDIR} ${STAGEDIR}${WEBWARE_MASTER_DIR}
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${WEBWARE_MASTER_DIR}

	@ ${ECHO} '---> Installing start/stop script'
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	${SED} -e "s|%%WEBKIT_HOME_DIR%%|${WEBKIT_HOME_DIR}|g" \
		< ${FILESDIR}/webkit.sh.tmpl \
		> ${STAGEDIR}${PREFIX}/etc/rc.d/webkit.sh-dist
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/etc/rc.d/webkit.sh-dist && \
	${CHOWN} root:wheel ${STAGEDIR}${PREFIX}/etc/rc.d/webkit.sh-dist

post-install:
	@ ${ECHO} '---> Compiling Python files and making webkit home directory'
	${SETENV} ${INSTALL_ENV} STAGEDIR=${STAGEDIR} ${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	${FIND} ${STAGEDIR} \( -name "*.pyc" -o -name "*.html" -o -name "*.cgi" -o -name "*.log" -o -name "*.py" \) -exec ${REINPLACE_CMD} -e "s|${STAGEDIR}||g" {} \;
	${FIND} ${STAGEDIR} -name "*.bak" -exec ${RM} {} \;

.include <bsd.port.post.mk>
