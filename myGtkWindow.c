#include <gtk/gtk.h>

const char *title;
int width, height;

int main (int argc, char **argv) {

    gtk_init(&argc, &argv);
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Title Goes Here");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 500);
    //gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    //gtk_window_maximize(GTK_WINDOW(window));

    title = gtk_window_get_title(GTK_WINDOW(window));
    printf("Your title is: %s\n", title);

    gtk_window_get_size(GTK_WINDOW(window), &width, &height);
    printf("width = %d, height = %d\n", width, height);

    printf("GTK window is decorated? %d\n", gtk_window_get_decorated(GTK_WINDOW(window)));
    printf("GTK window is maximized? %d\n", gtk_window_is_maximized(GTK_WINDOW(window)));
    printf("GTK window is active? %d\n", gtk_window_is_active(GTK_WINDOW(window)));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}