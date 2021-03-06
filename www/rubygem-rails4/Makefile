# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	4.1.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MVC web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionmailer4>=${PORTVERSION}:${PORTSDIR}/mail/rubygem-actionmailer4 \
		rubygem-actionpack4>=${PORTVERSION}:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-actionview>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-actionview \
		rubygem-activemodel4>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-activerecord4>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord4 \
		rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-bundler>=1.0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-railties4>=${PORTVERSION}:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-activeresource4>=4.0.0:${PORTSDIR}/www/rubygem-activeresource4 \
		rubygem-builder32>=3.2.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-sprockets-rails>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails \
		rubygem-rake>=10.1.1:${PORTSDIR}/devel/rubygem-rake \
		rubygem-sqlite3>=1.3.9:${PORTSDIR}/databases/rubygem-sqlite3 \
		rubygem-execjs>=2.2.1:${PORTSDIR}/devel/rubygem-execjs \
		rubygem-coffee-rails4>=4.0.1:${PORTSDIR}/devel/rubygem-coffee-rails4 \
		rubygem-sass-rails4>=4.0.3:${PORTSDIR}/textproc/rubygem-sass-rails4 \
		rubygem-spring>=1.1.3:${PORTSDIR}/devel/rubygem-spring \
		rubygem-jquery-rails4>=3.1.2:${PORTSDIR}/www/rubygem-jquery-rails4 \
		rubygem-jbuilder>=2.1.3:${PORTSDIR}/devel/rubygem-jbuilder \
		rubygem-uglifier>=2.5.0:${PORTSDIR}/www/rubygem-uglifier \
		rubygem-sprockets211>=2.11.0:${PORTSDIR}/devel/rubygem-sprockets211 \
		rubygem-rdoc>=0:${PORTSDIR}/devel/rubygem-rdoc \
		rubygem-thread_safe>=0.3.4:${PORTSDIR}/devel/rubygem-thread_safe \
		rubygem-turbolinks>=2.3.0:${PORTSDIR}/www/rubygem-turbolinks \
		rubygem-sass>=3.4.1:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-sdoc>=0.4.1:${PORTSDIR}/devel/rubygem-sdoc

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

USES=		cpe

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

OPTIONS_DEFINE=	FCGI PASSENGER MEMCACHE_CLIENT
FCGI_DESC=	FastCGI backend
MONGRELCLUSTER_DESC=	Mongrel Cluster backend
PASSENGER_DESC=	Passenger backend
MEMCACHE_CLIENT_DESC=	MemCache-Client support
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

FCGI_RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/fcgi.so:${PORTSDIR}/www/ruby-fcgi
MEMCACHE_CLIENT_RUN_DEPENDS=	rubygem-memcache-client>=1.2.0:${PORTSDIR}/databases/rubygem-memcache-client
PASSENGER_RUN_DEPENDS=	rubygem-passenger>=2.2.15:${PORTSDIR}/www/rubygem-passenger

.include <bsd.port.mk>
