#include <gtk4/gtk4.H>

int main(int argc, char argv){
    GtkWidget *window;
    GtkWidget *button;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new_with_label
        ("Click Me!");
}