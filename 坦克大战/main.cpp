//===============================
//�������ƣ�̹�˴�ս
//�汾�ţ�1.0
//�����ˣ�������
//
//����ʱ�䣺2017.3.27
//�깤ʱ�䣺2017.5.18
//��������10065��
//�������ڣ�21 ��
//
//===============================

#include"functions.h"
athena::ADBConnector DB;

int main()
{
	ege::setinitmode(ege::INIT_ANIMATION + ege::INIT_WITHLOGO);
	// ͼ�γ�ʼ��
	ege::initgraph(Win_W, Win_H);//��ʼ����ͼ����
	setcaption("̹�˴�ս Demo"); //�޸Ĵ�������
	setbkmode(TRANSPARENT);//�����������ʱ�ı���ģʽΪ͸��

	DB.connectTo("localhost", "siri", "root", "", 3306);
	if (!DB.isConnected())
	{
		setcolor(WHITE);
		setfont(50, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy((Win_W - 400) / 2, 250, "���ݿ�����ʧ��!");
		ege::getch();
		return 0;
	}
	DB.query("update battle_city set count=count+1");
	// �������ʼ��
	ege::randomize();
	// ������ѭ��
	mainloop();
	// �رջ�ͼ�豸
	ege::closegraph();

	return 0;
}