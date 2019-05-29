#include <QApplication>
#include <gtk/gtk.h>
#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QDataStream>

typedef struct
{
    GtkWidget* G_lineedit;
    GtkWidget* G_label;
}Transmit_Ds;

void clicked_OK(GtkWidget* _Sig_Instance,gpointer InstanceContainer)
{
    const char* p=gtk_entry_get_text((GtkEntry*)((*((Transmit_Ds*)InstanceContainer)).G_lineedit));
    gtk_label_set_label((GtkLabel*)((*((Transmit_Ds*)InstanceContainer)).G_label),p);
}

void GTK_WidgetInitShow(int argc, char *argv[])
{
    gtk_init (&argc, &argv);

    GdkColor color1;
    color1.red = 0xffff;
    color1.green = 0x0000;
    color1.blue = 0x0000;

    GdkColor color2;
    color2.red = 0x0000;
    color2.green = 0xffff;
    color2.blue = 0x0000;

    GtkWidget *G_f1label1 = gtk_label_new("Fream1Label");//布局范围测试Label1
    GtkWidget *G_f1label2 = gtk_label_new("Fream2Label");//布局范围测试Label2
    GtkWidget *G_f1vbox = gtk_vbox_new(TRUE,2);//测试Label布局容器
    gtk_widget_modify_bg(G_f1label1,GTK_STATE_NORMAL, &color2);//设置G_f1label1组件颜色
    gtk_widget_modify_bg(G_f1label2,GTK_STATE_NORMAL, &color1);//设置G_f1label2组件颜色

    gtk_container_add(GTK_CONTAINER(G_f1vbox) ,G_f1label1);//纵向布局添加元素
    gtk_container_add(GTK_CONTAINER(G_f1vbox) ,G_f1label2);//纵向布局添加元素

    GtkWidget *G_frameInType = gtk_frame_new("freamIn");//边框修饰1
    GtkWidget *G_frameOutType = gtk_frame_new("freamOut");//边框修饰2

    GtkWidget *G_tabel = gtk_table_new(2,1,TRUE);//tabelLayout
    GtkWidget *G_ButtonBox =gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);//按钮布局控件
    GtkWidget *G_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);//Widget承载界面
    GtkWidget *G_label = gtk_label_new("请输入内容");//输入显示label
    GtkWidget *G_okbutton = gtk_button_new_with_label("Ok");//确认按钮
    GtkWidget *G_closebutton = gtk_button_new_with_label("Close");//取消按钮
    GtkWidget *G_vbox = gtk_vbox_new(TRUE,10);//纵向布局
    GtkWidget *G_lineedit = gtk_entry_new();//编辑文本框
    GtkWidget *G_checkbutton = gtk_check_button_new_with_label("check_button");//点击按钮

    gtk_frame_set_shadow_type(GTK_FRAME(G_frameInType),GTK_SHADOW_IN);//边框修饰下效果内部阴影
    gtk_frame_set_shadow_type(GTK_FRAME(G_frameOutType),GTK_SHADOW_ETCHED_OUT);//边框修饰下效果外部淡入阴影

    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_frameInType,0,1,0,3);//空间添加布局
    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_frameOutType,1,2,3,8);

    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_f1vbox,0,1,1,3);
    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_label,0,1,3,4);
    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_lineedit,0,1,4,5);

    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_checkbutton,0,1,5,6);
    gtk_table_attach_defaults(GTK_TABLE(G_tabel),G_ButtonBox,0,1,6,7);

    gtk_container_add(GTK_CONTAINER(G_ButtonBox) ,G_okbutton);//容器box布局
    gtk_container_add(GTK_CONTAINER(G_ButtonBox) ,G_closebutton);
    gtk_container_add(GTK_CONTAINER(G_vbox) ,G_tabel);//容器box布局
    gtk_container_add(GTK_CONTAINER(G_window) ,G_vbox);//贴到承载类上

    static Transmit_Ds TSDS;//参数结构体
    TSDS.G_label=G_label;//地址赋值
    TSDS.G_lineedit=G_lineedit;//地址赋值
    qDebug()<<TSDS.G_label<<TSDS.G_lineedit<<&TSDS;

    g_signal_connect(G_okbutton,"clicked",G_CALLBACK(clicked_OK),(gpointer)&TSDS);//OkbuttonClicked信号槽链接
    g_signal_connect(G_window, "delete_event", gtk_main_quit, NULL);//删除事件信号槽链接
    gtk_widget_show_all(G_window); //gtk_loop function
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   //Qt-Gui入口函数
    GTK_WidgetInitShow(argc,argv);//GTK-GUI入口函数

    //    QMainWindow w;
    //    QLabel* label=new QLabel("this Qt Label Widget",&w);
    //    w.show();

    gtk_main();      //GTK return void
    return a.exec(); //QT return int
}
