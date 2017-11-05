// Algoritma pembuat lingkaran
// Team : Gacha ampas (Modifikasi)

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void lingkaran(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 400;
int window_height = 300;

//  judul window
char *title_window = "Algoritma Pembuat Lingkaran";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// atur posisi window agar di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //atur ukuran window 
	glutInitWindowPosition(window_x, window_y); //atur posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // display RGB dan double buffer
	glutCreateWindow(title_window);

	init(); // jalankan fungsi init
	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
}

void init()
{
	glClearColor(1.1, 1.1, 1.1, 1.1); // background color
	glColor3f(0.0, 0.0, 1.1); //warna titik
	glPointSize(3.0); //ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	lingkaran(); //jalankan fungsi lingkaran
	glutSwapBuffers(); //swap buffer 
}

void lingkaran(void) {
	//tentukan titik pusat dan jari-jari
	int xc,yc,r;
	r = 100;
	xc = 200;
	yc = 200;

	//hitung p awal dan set nilai awal untuk x dan y
	int p = 1-r;
	int x = 0;
	int y = r;

	glBegin(GL_POINTS);

	//perulangan untuk menggambar titik
	while (x <= y) {
		x++; //tambah nilai x
		if (p < 0) { 
			p += 2 * x + 1; //hitung p selanjutnya jika p < 0 
		}
		else {
			y--; //kurangi nilai y
			p += 2 * (x - y) + 1; //hitung p selanjutnya jika p > 0 atau p = 0
		}

		// translasi terhadap titik pusat dan cerminkan
		glVertex2i(xc + x, yc + y); //posisi atas samping kanan  
		glVertex2i(xc - x, yc + y); //posisi atas samping kiri
		glVertex2i(xc + x, yc - y); //posisi bawah serong kanan	
		glVertex2i(xc - x, yc - y); //posisi bawah serong kiri
		glVertex2i(xc + y, yc + x); //posisi kanan serong atas
		glVertex2i(xc - y, yc + x); //posisi kiri serong atas
		glVertex2i(xc + y, yc - x); //posisi kanan serong bawah
		glVertex2i(xc - y, yc - x); //poisisi kiri serong bawah
	}

	glEnd();
	glFlush();
}