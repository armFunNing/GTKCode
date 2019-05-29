#include <QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <glib/gthread.h>

#include <QStringList>
#include <QDebug>

#define GTK_MAIN(argc,argv) (GTK_WidgetInitShow(argc,argv))
#define MEM_ADD(a,b)    (add(a,b))

static int add(int a, int b)
{
        g_print("add:%d",a+b);
}

static int GTK_WidgetInitShow(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    GTK_MAIN(argc,argv);//GTK-GUI入口函数
////    printf("define function return:%d",MEM_ADD(10,20));
//    gtk_main();      //GTK return void

    QStringList stl={"aa","bb"};
    qDebug()<<stl.at(0);
    return a.exec();
}
