#include"Picture.h"
#include"functions.h"

Picture::Picture()
{

	//��ը
	//----------------------------
	getimage(explode_1, "��Դ��\\ͼƬ\\��ը\\1.png");
	getimage(explode_2, "��Դ��\\ͼƬ\\��ը\\2.png");
	getimage(explode_3, "��Դ��\\ͼƬ\\��ը\\3.png");
	getimage(explode_4, "��Դ��\\ͼƬ\\��ը\\4.png");
	getimage(explode_5, "��Դ��\\ͼƬ\\��ը\\5.png");
	getimage(explode_6, "��Դ��\\ͼƬ\\��ը\\6.png");
	getimage(explode_7, "��Դ��\\ͼƬ\\��ը\\7.png");
	getimage(explode_8, "��Դ��\\ͼƬ\\��ը\\8.png");

	//����
	//-----------------------------
	getimage(bomb, "��Դ��\\ͼƬ\\����\\bomb.png");
	getimage(life, "��Դ��\\ͼƬ\\����\\life.png");
	getimage(shield, "��Դ��\\ͼƬ\\����\\shield.png");
	getimage(star, "��Դ��\\ͼƬ\\����\\star.png");
	getimage(timer, "��Դ��\\ͼƬ\\����\\timer.png");

	//��ͼ
	//-----------------------------
	////20X20
	getimage(wall_steel_2, "��Դ��\\ͼƬ\\��ͼ\\20X20\\wall_steel_2.png");
	getimage(wall_stone_2, "��Դ��\\ͼƬ\\��ͼ\\20X20\\wall_stone_2.png");
	getimage(grass_2, "��Դ��\\ͼƬ\\��ͼ\\20X20\\grass_2.png");
	getimage(water_2, "��Դ��\\ͼƬ\\��ͼ\\20X20\\water_2.png");

	////40X40
	getimage(wall_steel_4, "��Դ��\\ͼƬ\\��ͼ\\40X40\\wall_steel_4.png");
	getimage(wall_stone_4, "��Դ��\\ͼƬ\\��ͼ\\40X40\\wall_stone_4.png");
	getimage(destory, "��Դ��\\ͼƬ\\��ͼ\\40X40\\destory.png");
	getimage(grass_4, "��Դ��\\ͼƬ\\��ͼ\\40X40\\grass_4.png");
	getimage(water_4, "��Դ��\\ͼƬ\\��ͼ\\40X40\\water_4.png");
	getimage(home, "��Դ��\\ͼƬ\\��ͼ\\40X40\\home.png");
	getimage(enemyborn, "��Դ��\\ͼƬ\\��ͼ\\40X40\\enemyborn.png");
	getimage(player1born, "��Դ��\\ͼƬ\\��ͼ\\40X40\\player1born.png");
	getimage(player2born, "��Դ��\\ͼƬ\\��ͼ\\40X40\\player2born.png");
	getimage(d_delete, "��Դ��\\ͼƬ\\��ͼ\\40X40\\delete.png");
	getimage(d_save, "��Դ��\\ͼƬ\\��ͼ\\40X40\\save.png");
	getimage(d_return, "��Դ��\\ͼƬ\\��ͼ\\40X40\\return.png");
	getimage(d_clean, "��Դ��\\ͼƬ\\��ͼ\\40X40\\clean.png");

	////��ͼԤ��
	//////PVE
	getimage(map_PVE_1, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\1.jpg");
	getimage(map_PVE_2, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\2.jpg");
	getimage(map_PVE_3, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\3.jpg");
	getimage(map_PVE_4, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\4.jpg");
	getimage(map_PVE_5, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\5.jpg");
	getimage(map_PVE_6, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\6.jpg");
	getimage(map_PVE_7, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\7.jpg");
	getimage(map_PVE_8, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\8.jpg");
	getimage(map_PVE_9, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\9.jpg");
	getimage(map_PVE_10, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\10.jpg");
	getimage(map_PVE_11, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\11.jpg");
	getimage(map_PVE_12, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\12.jpg");
	getimage(map_PVE_13, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\13.jpg");
	getimage(map_PVE_14, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\14.jpg");
	getimage(map_PVE_15, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\15.jpg");
	getimage(map_PVE_16, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\16.jpg");
	getimage(map_PVE_17, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\17.jpg");
	getimage(map_PVE_18, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\18.jpg");
	getimage(map_PVE_19, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\19.jpg");
	getimage(map_PVE_20, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\PVE\\20.jpg");

	getimage(map_lock, "��Դ��\\ͼƬ\\��ͼ\\��ͼԤ��\\lock.jpg");



	//����
	//-----------------------------
	getimage(over, "��Դ��\\ͼƬ\\����\\over.png");

	getimage(selects, "��Դ��\\ͼƬ\\����\\selects.png");
	getimage(solo_selects, "��Դ��\\ͼƬ\\����\\solo_selects.png");
	getimage(design_selects, "��Դ��\\ͼƬ\\����\\design_selects.png");

	getimage(title, "��Դ��\\ͼƬ\\����\\title.png");
	getimage(end, "��Դ��\\ͼƬ\\����\\end.png");
	getimage(BattleCity, "��Դ��\\ͼƬ\\����\\BattleCity.png");
	getimage(selecttank, "��Դ��\\ͼƬ\\����\\selecttank.png");
	getimage(copyright, "��Դ��\\ͼƬ\\����\\copyright.png");

	getimage(instruction_solo, "��Դ��\\ͼƬ\\����\\instruction_solo.png");
	//̹��
	//-----------------------------
	////����
	getimage(born_1, "��Դ��\\ͼƬ\\̹��\\����\\1.png");
	getimage(born_2, "��Դ��\\ͼƬ\\̹��\\����\\2.png");
	getimage(born_3, "��Դ��\\ͼƬ\\̹��\\����\\3.png");
	getimage(born_4, "��Դ��\\ͼƬ\\̹��\\����\\4.png");

	////����
	////---------------------------
	////��̹ͨ��
	////---------------------------
	//////1
	getimage(ordinary_1_A, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\1\\A.png");
	getimage(ordinary_1_D, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\1\\D.png");
	getimage(ordinary_1_S, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\1\\S.png");
	getimage(ordinary_1_W, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\1\\W.png");
	//////2
	getimage(ordinary_2_A, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\2\\A.png");
	getimage(ordinary_2_D, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\2\\D.png");
	getimage(ordinary_2_S, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\2\\S.png");
	getimage(ordinary_2_W, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\2\\W.png");
	//////3
	getimage(ordinary_3_A, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\3\\A.png");
	getimage(ordinary_3_D, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\3\\D.png");
	getimage(ordinary_3_S, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\3\\S.png");
	getimage(ordinary_3_W, "��Դ��\\ͼƬ\\̹��\\����\\��̹ͨ��\\3\\W.png");
	////����̹��
	////---------------------------
	//////1
	getimage(heavy_1_A, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\1\\A.png");
	getimage(heavy_1_D, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\1\\D.png");
	getimage(heavy_1_S, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\1\\S.png");
	getimage(heavy_1_W, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\1\\W.png");
	//////2
	getimage(heavy_2_A, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\2\\A.png");
	getimage(heavy_2_D, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\2\\D.png");
	getimage(heavy_2_S, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\2\\S.png");
	getimage(heavy_2_W, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\2\\W.png");
	//////3
	getimage(heavy_3_A, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\3\\A.png");
	getimage(heavy_3_D, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\3\\D.png");
	getimage(heavy_3_S, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\3\\S.png");
	getimage(heavy_3_W, "��Դ��\\ͼƬ\\̹��\\����\\����̹��\\3\\W.png");

	////���
	////-----------------------------
	//////���1
	getimage(player_1_A, "��Դ��\\ͼƬ\\̹��\\���\\���1\\A.png");
	getimage(player_1_D, "��Դ��\\ͼƬ\\̹��\\���\\���1\\D.png");
	getimage(player_1_S, "��Դ��\\ͼƬ\\̹��\\���\\���1\\S.png");
	getimage(player_1_W, "��Դ��\\ͼƬ\\̹��\\���\\���1\\W.png");
	//////���2
	getimage(player_2_A, "��Դ��\\ͼƬ\\̹��\\���\\���2\\A.png");
	getimage(player_2_D, "��Դ��\\ͼƬ\\̹��\\���\\���2\\D.png");
	getimage(player_2_S, "��Դ��\\ͼƬ\\̹��\\���\\���2\\S.png");
	getimage(player_2_W, "��Դ��\\ͼƬ\\̹��\\���\\���2\\W.png");

	////�ӵ�
	////----------------------------
	//////����
	getimage(E_missile, "��Դ��\\ͼƬ\\̹��\\�ӵ�\\����\\missile.png");
	//////���
	getimage(P_missile, "��Դ��\\ͼƬ\\̹��\\�ӵ�\\���\\missile.png");

}

Picture::~Picture()
{
	//����
	delimage(canvas);

	//��ը
	//----------------------------
	delimage(explode_1);
	delimage(explode_2);
	delimage(explode_3);
	delimage(explode_4);
	delimage(explode_5);
	delimage(explode_6);
	delimage(explode_7);
	delimage(explode_8);

	//����
	//-----------------------------
	delimage(bomb);
	delimage(life);
	delimage(shield);
	delimage(star);
	delimage(timer);

	//��ͼ
	//-----------------------------
	////20X20
	delimage(wall_steel_2);
	delimage(wall_stone_2);
	delimage(grass_2);
	delimage(water_2);

	////40X40
	delimage(wall_steel_4);
	delimage(wall_stone_4);
	delimage(destory);
	delimage(grass_4);
	delimage(water_4);
	delimage(home);
	delimage(enemyborn);
	delimage(player1born);
	delimage(player2born);
	delimage(d_clean);
	delimage(d_delete);
	delimage(d_return);
	delimage(d_save);

	////��ͼԤ��
	//////PVE
	delimage(map_PVE_1);
	delimage(map_PVE_2);
	delimage(map_PVE_3);
	delimage(map_PVE_4);
	delimage(map_PVE_5);
	delimage(map_PVE_6);
	delimage(map_PVE_7);
	delimage(map_PVE_8);
	delimage(map_PVE_9);
	delimage(map_PVE_10);
	delimage(map_PVE_11);
	delimage(map_PVE_12);
	delimage(map_PVE_13);
	delimage(map_PVE_14);
	delimage(map_PVE_15);
	delimage(map_PVE_16);
	delimage(map_PVE_17);
	delimage(map_PVE_18);
	delimage(map_PVE_19);
	delimage(map_PVE_20);

	delimage(map_lock);

	//����
	//-----------------------------
	delimage(over);

	delimage(selects);
	delimage(solo_selects);
	delimage(design_selects);

	delimage(title);
	delimage(end);
	delimage(BattleCity);
	delimage(selecttank);
	delimage(copyright);

	delimage(instruction_solo);

	//̹��
	//-----------------------------
	////����
	delimage(born_1);
	delimage(born_2);
	delimage(born_3);
	delimage(born_4);

	////����
	////---------------------------
	////��̹ͨ��
	////---------------------------
	//////1
	delimage(ordinary_1_A);
	delimage(ordinary_1_D);
	delimage(ordinary_1_S);
	delimage(ordinary_1_W);
	//////2
	delimage(ordinary_2_A);
	delimage(ordinary_2_D);
	delimage(ordinary_2_S);
	delimage(ordinary_2_W);
	//////3
	delimage(ordinary_3_A);
	delimage(ordinary_3_D);
	delimage(ordinary_3_S);
	delimage(ordinary_3_W);
	////����̹��
	////---------------------------
	//////1
	delimage(heavy_1_A);
	delimage(heavy_1_D);
	delimage(heavy_1_S);
	delimage(heavy_1_W);
	//////2
	delimage(heavy_2_A);
	delimage(heavy_2_D);
	delimage(heavy_2_S);
	delimage(heavy_2_W);
	//////3
	delimage(heavy_3_A);
	delimage(heavy_3_D);
	delimage(heavy_3_S);
	delimage(heavy_3_W);

	////���
	////-----------------------------
	//////���1
	delimage(player_1_A);
	delimage(player_1_D);
	delimage(player_1_S);
	delimage(player_1_W);
	//////���2
	delimage(player_2_A);
	delimage(player_2_D);
	delimage(player_2_S);
	delimage(player_2_W);

	////�ӵ�
	////----------------------------
	//////����
	delimage(E_missile);
	//////���
	delimage(P_missile);
}

void Picture::clear()
{
	cleardevice();
	cleardevice(canvas);
	settarget(canvas);
}

void Picture::rend()
{
	settarget(NULL);
	putimage(0, 0, canvas);
}
