QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QMAKE_LFLAGS += -no-pie

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    signinexistingcustomer.cpp \
    signinnewcustomer.cpp \
    Database.cpp \
    Customer.cpp \
    CustomerDatabase.cpp \
    Database.cpp \
    SignInOut.cpp \
    Sync.cpp \
    tempUser.cpp \
    windowaboutquicktrack.cpp \
    windowlogin.cpp

HEADERS += \
    mainwindow.h \
    signinexistingcustomer.h \
    signinnewcustomer.h \
    Database.h \
    lib/include/jdbc/cppconn/build_config.h \
    lib/include/jdbc/cppconn/config.h \
    lib/include/jdbc/cppconn/connection.h \
    lib/include/jdbc/cppconn/datatype.h \
    lib/include/jdbc/cppconn/driver.h \
    lib/include/jdbc/cppconn/exception.h \
    lib/include/jdbc/cppconn/metadata.h \
    lib/include/jdbc/cppconn/parameter_metadata.h \
    lib/include/jdbc/cppconn/prepared_statement.h \
    lib/include/jdbc/cppconn/resultset.h \
    lib/include/jdbc/cppconn/resultset_metadata.h \
    lib/include/jdbc/cppconn/sqlstring.h \
    lib/include/jdbc/cppconn/statement.h \
    lib/include/jdbc/cppconn/variant.h \
    lib/include/jdbc/cppconn/version_info.h \
    lib/include/jdbc/cppconn/warning.h \
    lib/include/jdbc/mysql_connection.h \
    lib/include/jdbc/mysql_driver.h \
    lib/include/jdbc/mysql_error.h \
    lib/include/mysql/jdbc.h \
    lib/include/mysqlx/common/api.h \
    lib/include/mysqlx/common/error.h \
    lib/include/mysqlx/common/op_if.h \
    lib/include/mysqlx/common/settings.h \
    lib/include/mysqlx/common/util.h \
    lib/include/mysqlx/common/value.h \
    lib/include/mysqlx/devapi/detail/crud.h \
    lib/include/mysqlx/devapi/detail/error.h \
    lib/include/mysqlx/devapi/detail/result.h \
    lib/include/mysqlx/devapi/detail/row.h \
    lib/include/mysqlx/devapi/detail/session.h \
    lib/include/mysqlx/devapi/detail/settings.h \
    lib/include/mysqlx/devapi/collations.h \
    lib/include/mysqlx/devapi/collection_crud.h \
    lib/include/mysqlx/devapi/common.h \
    lib/include/mysqlx/devapi/crud.h \
    lib/include/mysqlx/devapi/document.h \
    lib/include/mysqlx/devapi/error.h \
    lib/include/mysqlx/devapi/executable.h \
    lib/include/mysqlx/devapi/mysql_charsets.h \
    lib/include/mysqlx/devapi/mysql_collations.h \
    lib/include/mysqlx/devapi/result.h \
    lib/include/mysqlx/devapi/row.h \
    lib/include/mysqlx/devapi/settings.h \
    lib/include/mysqlx/devapi/table_crud.h \
    lib/include/mysqlx/common.h \
    lib/include/mysqlx/common_constants.h \
    lib/include/mysqlx/xapi.h \
    lib/include/mysqlx/xdevapi.h \
    Database.h \
    mainwindow.h \
    signinexistingcustomer.h \
    signinnewcustomer.h \
    Customer.h \
    CustomerDatabase.h \
    Database.h \
    mainwindow.h \
    signinexistingcustomer.h \
    signinnewcustomer.h \
    SignInOut.h \
    Sync.h \
    tempUser.h \
    windowaboutquicktrack.h \
    windowlogin.h

FORMS += \
    mainwindow.ui \
    signinexistingcustomer.ui \
    signinnewcustomer.ui \
    windowaboutquicktrack.ui \
    windowlogin.ui

TRANSLATIONS += \
    FastTrack_en_CA.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DISTFILES += \
    lib/lib/libmysqlcppconn.so.7.8.0.22 \
    lib/lib/plugin/authentication_ldap_sasl_client.so \
    lib/lib/private/libcrypto.so.1.1 \
    lib/lib/private/libssl.so.1.1 \
    lib/lib/libmysqlcppconn.so.7.8.0.22 \
    lib/lib/libmysqlcppconn8.so.2.8.0.22 \
    lib/INFO_BIN \
    lib/INFO_SRC \
    lib/LICENSE \
    lib/README

unix: CONFIG += link_pkgconfig
unix: LIBS += -L lib/lib -lmysqlcppconn
unix: INCLUDEPATH += -I lib/include/jdbc/cppconn

RESOURCES += \
    resource.qrc
