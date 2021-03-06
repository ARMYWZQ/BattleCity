#include "bulltes.h"
#include"tanke_enemy.h"
#include"tank_player.h"


bulltes::bulltes()
{
	bullet = false;
	isplayer = 1;
}


bulltes::~bulltes()
{
}

void bulltes::update(map & map, int(*tankmap)[26], int(*bulltemap)[26], tank_player& player_tank, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int& playerlife, int& enemynum, int& score)
{
	update_move(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
	update_xy();
}

void bulltes::update(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int & playerlife, int & enemynum, int & score)
{
	update_move(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
	update_xy();
}

void bulltes::update(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int playerlife[])
{
	update_move(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
	update_xy();
}

void bulltes::render(Picture& picture)
{
	if (bullet)
		if (isplayer)
			putimage_withalpha(NULL, picture.P_missile, x, y);
		else
			putimage_withalpha(NULL, picture.E_missile, x, y);
}

void bulltes::init(int isplayer, int aimx, int aimy, direction direct, int speed)
{
	count = 0;
	bullet = true;
	this->speed = speed;
	this->isplayer = isplayer;
	this->direct = direct;

	switch (direct)
	{
	case Up:
		this->aimx = aimx;
		this->aimy = aimy - 1;
		break;
	case Down:
		this->aimx = aimx;
		this->aimy = aimy + 2;
		break;
	case Right:
		this->aimx = aimx + 2;
		this->aimy = aimy;
		break;
	case Left:
		this->aimx = aimx - 1;
		this->aimy = aimy;
		break;
	}

	x = map_x + this->aimx * 20;
	y = map_y + this->aimy * 20;

	switch (direct)
	{
	case Up:
	case Down:
		x += 10;
		break;
	case Right:
	case Left:
		y += 10;
		break;
	}

	music.mu_Switch();
}

void bulltes::BulletHit(map & map, gameState & state)
{
	switch (direct)
	{
	case Up:
	case Down:
		if (map.getmember(0, aimx, aimy) == stone)
			map.setmember(0, aimx, aimy, land);
		if (map.getmember(0, aimx + 1, aimy) == stone)
			map.setmember(0, aimx + 1, aimy, land);
		if (map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy) == home)
		{
			if (map.getmode() == PVE)
			{
				map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
				state = lose;
			}
			else
			{
				if (aimx < 13)
				{
					map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
					state = lose1;
				}
				else
				{
					map.setmember(1, map.getHome_x(1), map.getHome_y(1), destory_h);
					state = lose2;
				}
			}
		}
		if (map.getmember(1, aimx + 1, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home)
		{
			if (map.getmode() == PVE)
			{
				map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
				state = lose;
			}
			else
			{
				if (aimx < 13)
				{
					map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
					state = lose1;
				}
				else
				{
					map.setmember(1, map.getHome_x(1), map.getHome_y(1), destory_h);
					state = lose2;
				}
			}
		}
		break;
	case Right:
	case Left:
		if (map.getmember(0, aimx, aimy) == stone)
			map.setmember(0, aimx, aimy, land);
		if (map.getmember(0, aimx, aimy + 1) == stone)
			map.setmember(0, aimx, aimy + 1, land);
		if (map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy) == home)
		{
			if (map.getmode() == PVE)
			{
				map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
				state = lose;
			}
			else
			{
				if (aimx < 13)
				{
					map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
					state = lose1;
				}
				else
				{
					map.setmember(1, map.getHome_x(1), map.getHome_y(1), destory_h);
					state = lose2;
				}
			}
		}
		if (map.getmember(1, aimx, aimy + 1) == home_h || map.getmember(1, aimx, aimy + 1) == home)
		{
			if (map.getmode() == PVE)
			{
				map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
				state = lose;
			}
			else
			{
				if (aimx < 13)
				{
					map.setmember(1, map.getHome_x(0), map.getHome_y(0), destory_h);
					state = lose1;
				}
				else
				{
					map.setmember(1, map.getHome_x(1), map.getHome_y(1), destory_h);
					state = lose2;
				}
			}
		}
		break;
	}
}


void bulltes::BulletHitPlus(map & map, int(*tankmap)[26], int(*bulltemap)[26], tank_player& player_tank, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int& playerlife, int& enemynum, int& score)
{
	switch (direct)
	{
	case Up:
	case Down:
		if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if (((enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx == aimx && enemyQueue.front()->aimy + 1 == aimy) || (enemyQueue.front()->aimx + 1 == aimx && enemyQueue.front()->aimy + 1 == aimy)) || ((enemyQueue.front()->aimx == aimx + 1 && enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx + 1 == aimx + 1 && enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx == aimx + 1 && enemyQueue.front()->aimy + 1 == aimy) || (enemyQueue.front()->aimx + 1 == aimx + 1 && enemyQueue.front()->aimy + 1 == aimy)))
					{
						if (enemyQueue.front()->level > 1)
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							enemyQueue.front()->level--;
							music.mu_Hit_Tank();
							break;
						}
						else
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							bombQueue.push(enemyQueue.front()->x, enemyQueue.front()->y);
							creatProp(enemyQueue.front()->aimx, enemyQueue.front()->aimy, propertyQueue);
							deadenemyQueue.push(enemyQueue.front());
							enemyQueue.pop();
							music.mu_Dead_Enemy();
							enemynum--;
							break;
						}
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				if (!player_tank.count_sheld)
				{
					if (((player_tank.aimx == aimx&&player_tank.aimy == aimy) || (player_tank.aimx + 1 == aimx&&player_tank.aimy == aimy) || (player_tank.aimx == aimx&&player_tank.aimy + 1 == aimy) || (player_tank.aimx + 1 == aimx&&player_tank.aimy + 1 == aimy)) || ((player_tank.aimx == aimx + 1 && player_tank.aimy == aimy) || (player_tank.aimx + 1 == aimx + 1 && player_tank.aimy == aimy) || (player_tank.aimx == aimx + 1 && player_tank.aimy + 1 == aimy) || (player_tank.aimx + 1 == aimx + 1 && player_tank.aimy + 1 == aimy)))
					{
						if (player_tank.level == 2)
						{
							player_tank.level--;
							music.mu_Hit_Tank();
						}
						else
						{
							player_tank.init_tank_player(bornQueue, map);
							playerlife--;
							music.mu_Dead_Player();
						}
					}
				}
			}
		}
		break;
	case Left:
	case Right:
		if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if (((enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy + 1 == aimy) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy + 1 == aimy)) || ((enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy == aimy + 1) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy == aimy + 1) || (enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy + 1 == aimy + 1) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy + 1 == aimy + 1)))
					{
						if (enemyQueue.front()->level > 1)
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							enemyQueue.front()->level--;
							music.mu_Hit_Tank();
							break;
						}
						else
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							bombQueue.push(enemyQueue.front()->x, enemyQueue.front()->y);
							creatProp(enemyQueue.front()->aimx, enemyQueue.front()->aimy, propertyQueue);
							deadenemyQueue.push(enemyQueue.front());
							enemyQueue.pop();
							music.mu_Dead_Enemy();
							enemynum--;
							break;
						}
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				if (!player_tank.count_sheld)
				{
					if (((player_tank.aimx == aimx&&player_tank.aimy == aimy) || (player_tank.aimx + 1 == aimx&&player_tank.aimy == aimy) || (player_tank.aimx == aimx&&player_tank.aimy + 1 == aimy) || (player_tank.aimx + 1 == aimx&&player_tank.aimy + 1 == aimy)) || ((player_tank.aimx == aimx&&player_tank.aimy == aimy + 1) || (player_tank.aimx + 1 == aimx&&player_tank.aimy == aimy + 1) || (player_tank.aimx == aimx&&player_tank.aimy + 1 == aimy + 1) || (player_tank.aimx + 1 == aimx&&player_tank.aimy + 1 == aimy + 1)))
					{
						if (player_tank.level == 2)
						{
							player_tank.level--;
							music.mu_Hit_Tank();
						}
						else
						{
							player_tank.init_tank_player(bornQueue, map);
							playerlife--;
							music.mu_Dead_Player();
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
}

void bulltes::BulletHitPlus(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int & playerlife, int & enemynum, int & score)
{
	switch (direct)
	{
	case Up:
	case Down:
		if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if (((enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx == aimx && enemyQueue.front()->aimy + 1 == aimy) || (enemyQueue.front()->aimx + 1 == aimx && enemyQueue.front()->aimy + 1 == aimy)) || ((enemyQueue.front()->aimx == aimx + 1 && enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx + 1 == aimx + 1 && enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx == aimx + 1 && enemyQueue.front()->aimy + 1 == aimy) || (enemyQueue.front()->aimx + 1 == aimx + 1 && enemyQueue.front()->aimy + 1 == aimy)))
					{
						if (enemyQueue.front()->level > 1)
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							enemyQueue.front()->level--;
							music.mu_Hit_Tank();
							break;
						}
						else
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							bombQueue.push(enemyQueue.front()->x, enemyQueue.front()->y);
							creatProp(enemyQueue.front()->aimx, enemyQueue.front()->aimy, propertyQueue);
							deadenemyQueue.push(enemyQueue.front());
							enemyQueue.pop();
							music.mu_Dead_Enemy();
							enemynum--;
							break;
						}
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				if (!player_tank1.count_sheld)
				{
					if (((player_tank1.aimx == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx == aimx&&player_tank1.aimy + 1 == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy + 1 == aimy)) || ((player_tank1.aimx == aimx + 1 && player_tank1.aimy == aimy) || (player_tank1.aimx + 1 == aimx + 1 && player_tank1.aimy == aimy) || (player_tank1.aimx == aimx + 1 && player_tank1.aimy + 1 == aimy) || (player_tank1.aimx + 1 == aimx + 1 && player_tank1.aimy + 1 == aimy)))
					{
						if (player_tank1.level == 2)
						{
							player_tank1.level--;
							music.mu_Hit_Tank();
						}
						else
						{
							player_tank1.init_tank_player(bornQueue, map);
							playerlife--;
							music.mu_Dead_Player();
						}
					}
				}

				if (!player_tank2.count_sheld)
				{
					if (((player_tank2.aimx == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx == aimx&&player_tank2.aimy + 1 == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy + 1 == aimy)) || ((player_tank2.aimx == aimx + 1 && player_tank2.aimy == aimy) || (player_tank2.aimx + 1 == aimx + 1 && player_tank2.aimy == aimy) || (player_tank2.aimx == aimx + 1 && player_tank2.aimy + 1 == aimy) || (player_tank2.aimx + 1 == aimx + 1 && player_tank2.aimy + 1 == aimy)))
					{
						if (player_tank2.level == 2)
						{
							player_tank2.level--;
							music.mu_Hit_Tank();
						}
						else
						{
							player_tank2.init_tank_player(bornQueue, map, Up, false);
							playerlife--;
							music.mu_Dead_Player();
						}
					}
				}
			}
		}
		break;
	case Left:
	case Right:
		if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if (((enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy == aimy) || (enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy + 1 == aimy) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy + 1 == aimy)) || ((enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy == aimy + 1) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy == aimy + 1) || (enemyQueue.front()->aimx == aimx&&enemyQueue.front()->aimy + 1 == aimy + 1) || (enemyQueue.front()->aimx + 1 == aimx&&enemyQueue.front()->aimy + 1 == aimy + 1)))
					{
						if (enemyQueue.front()->level > 1)
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							enemyQueue.front()->level--;
							music.mu_Hit_Tank();
							break;
						}
						else
						{
							if (enemyQueue.front()->isHeavy)
								score += enemyQueue.front()->level * 200;
							else
								score += enemyQueue.front()->level * 100;
							bombQueue.push(enemyQueue.front()->x, enemyQueue.front()->y);
							creatProp(enemyQueue.front()->aimx, enemyQueue.front()->aimy, propertyQueue);
							deadenemyQueue.push(enemyQueue.front());
							enemyQueue.pop();
							music.mu_Dead_Enemy();
							enemynum--;
							break;
						}
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				if (!player_tank1.count_sheld)
				{
					if (((player_tank1.aimx == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx == aimx&&player_tank1.aimy + 1 == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy + 1 == aimy)) || ((player_tank1.aimx == aimx&&player_tank1.aimy == aimy + 1) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy == aimy + 1) || (player_tank1.aimx == aimx&&player_tank1.aimy + 1 == aimy + 1) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy + 1 == aimy + 1)))
					{
						if (player_tank1.level == 2)
						{
							player_tank1.level--;
							music.mu_Hit_Tank();
						}
						else
						{
							player_tank1.init_tank_player(bornQueue, map);
							playerlife--;
							music.mu_Dead_Player();
						}
					}
				}

				if (!player_tank2.count_sheld)
				{
					if (((player_tank2.aimx == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx == aimx&&player_tank2.aimy + 1 == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy + 1 == aimy)) || ((player_tank2.aimx == aimx&&player_tank2.aimy == aimy + 1) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy == aimy + 1) || (player_tank2.aimx == aimx&&player_tank2.aimy + 1 == aimy + 1) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy + 1 == aimy + 1)))
					{
						if (player_tank2.level == 2)
						{
							player_tank2.level--;
							music.mu_Hit_Tank();
						}
						else
						{
							player_tank2.init_tank_player(bornQueue, map, Up, false);
							playerlife--;
							music.mu_Dead_Player();
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
}

void bulltes::BulletHitPlus(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int playerlife[])
{
	switch (direct)
	{
	case Up:
	case Down:
		if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
		{

			if (!player_tank1.count_sheld)
			{
				if (((player_tank1.aimx == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx == aimx&&player_tank1.aimy + 1 == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy + 1 == aimy)) || ((player_tank1.aimx == aimx + 1 && player_tank1.aimy == aimy) || (player_tank1.aimx + 1 == aimx + 1 && player_tank1.aimy == aimy) || (player_tank1.aimx == aimx + 1 && player_tank1.aimy + 1 == aimy) || (player_tank1.aimx + 1 == aimx + 1 && player_tank1.aimy + 1 == aimy)))
				{
					if (player_tank1.level == 2)
					{
						player_tank1.level--;
						music.mu_Hit_Tank();
					}
					else
					{
						player_tank1.init_tank_player(bornQueue, map, Right);
						playerlife[0]--;
						music.mu_Dead_Player();
					}
				}
			}

			if (!player_tank2.count_sheld)
			{
				if (((player_tank2.aimx == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx == aimx&&player_tank2.aimy + 1 == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy + 1 == aimy)) || ((player_tank2.aimx == aimx + 1 && player_tank2.aimy == aimy) || (player_tank2.aimx + 1 == aimx + 1 && player_tank2.aimy == aimy) || (player_tank2.aimx == aimx + 1 && player_tank2.aimy + 1 == aimy) || (player_tank2.aimx + 1 == aimx + 1 && player_tank2.aimy + 1 == aimy)))
				{
					if (player_tank2.level == 2)
					{
						player_tank2.level--;
						music.mu_Hit_Tank();
					}
					else
					{
						player_tank2.init_tank_player(bornQueue, map, Left, false);
						playerlife[1]--;
						music.mu_Dead_Player();
					}
				}
			}
		}
		break;
	case Left:
	case Right:
		if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
		{
			if (!player_tank1.count_sheld)
			{
				if (((player_tank1.aimx == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy == aimy) || (player_tank1.aimx == aimx&&player_tank1.aimy + 1 == aimy) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy + 1 == aimy)) || ((player_tank1.aimx == aimx&&player_tank1.aimy == aimy + 1) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy == aimy + 1) || (player_tank1.aimx == aimx&&player_tank1.aimy + 1 == aimy + 1) || (player_tank1.aimx + 1 == aimx&&player_tank1.aimy + 1 == aimy + 1)))
				{
					if (player_tank1.level == 2)
					{
						player_tank1.level--;
						music.mu_Hit_Tank();
					}
					else
					{
						player_tank1.init_tank_player(bornQueue, map, Right);
						playerlife[0]--;
						music.mu_Dead_Player();
					}
				}
			}

			if (!player_tank2.count_sheld)
			{
				if (((player_tank2.aimx == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy == aimy) || (player_tank2.aimx == aimx&&player_tank2.aimy + 1 == aimy) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy + 1 == aimy)) || ((player_tank2.aimx == aimx&&player_tank2.aimy == aimy + 1) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy == aimy + 1) || (player_tank2.aimx == aimx&&player_tank2.aimy + 1 == aimy + 1) || (player_tank2.aimx + 1 == aimx&&player_tank2.aimy + 1 == aimy + 1)))
				{
					if (player_tank2.level == 2)
					{
						player_tank2.level--;
						music.mu_Hit_Tank();
					}
					else
					{
						player_tank2.init_tank_player(bornQueue, map, Left, false);
						playerlife[1]--;
						music.mu_Dead_Player();
					}
				}
			}
		}
		break;
	default:
		break;
	}
}

void bulltes::BulletHit_bullte(map & map, int(*tankmap)[26], int(*bulltemap)[26], tank_player & player_tank, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int & playerlife, int & enemynum, int & score)
{
	switch (direct)
	{
	case Up:
	case Down:
		if (bulltemap[aimx][aimy] == 1 || bulltemap[aimx + 1][aimy] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx + 1 == aimx&&enemyQueue.front()->bullte.aimy == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				int n = enemyQueue.size() - 1;
				enemyQueue.push(enemyQueue.front());
				enemyQueue.pop();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx + 1 == aimx&&enemyQueue.front()->bullte.aimy == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}

				if ((player_tank.bullte.aimx == aimx&&player_tank.bullte.aimy == aimy) || (player_tank.bullte.aimx + 1 == aimx&&player_tank.bullte.aimy == aimy))
				{
					player_tank.bullte.bullet = false;
				}
			}
		}
		break;
	case Left:
	case Right:
		if (bulltemap[aimx][aimy] == 1 || bulltemap[aimx][aimy + 1] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy + 1 == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				int n = enemyQueue.size() - 1;
				enemyQueue.push(enemyQueue.front());
				enemyQueue.pop();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy + 1 == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}

				if ((player_tank.bullte.aimx == aimx&&player_tank.bullte.aimy == aimy) || (player_tank.bullte.aimx == aimx&&player_tank.bullte.aimy + 1 == aimy))
				{
					player_tank.bullte.bullet = false;
				}
			}
		}
		break;
	default:
		break;
	}
}

void bulltes::BulletHit_bullte(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int & playerlife, int & enemynum, int & score)
{
	switch (direct)
	{
	case Up:
	case Down:
		if (bulletmap[aimx][aimy] == 1 || bulletmap[aimx + 1][aimy] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx + 1 == aimx&&enemyQueue.front()->bullte.aimy == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				int n = enemyQueue.size() - 1;
				enemyQueue.push(enemyQueue.front());
				enemyQueue.pop();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx + 1 == aimx&&enemyQueue.front()->bullte.aimy == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}

				if ((player_tank1.bullte.aimx == aimx&&player_tank1.bullte.aimy == aimy) || (player_tank1.bullte.aimx + 1 == aimx&&player_tank1.bullte.aimy == aimy))
				{
					player_tank1.bullte.bullet = false;
				}

				if ((player_tank2.bullte.aimx == aimx&&player_tank2.bullte.aimy == aimy) || (player_tank2.bullte.aimx + 1 == aimx&&player_tank2.bullte.aimy == aimy))
				{
					player_tank2.bullte.bullet = false;
				}
			}
		}
		break;
	case Left:
	case Right:
		if (bulletmap[aimx][aimy] == 1 || bulletmap[aimx][aimy + 1] == 1)
		{
			if (isplayer)
			{
				int n = enemyQueue.size();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy + 1 == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}
			}
			else
			{
				int n = enemyQueue.size() - 1;
				enemyQueue.push(enemyQueue.front());
				enemyQueue.pop();
				while (n--)
				{
					if ((enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy == aimy) || (enemyQueue.front()->bullte.aimx == aimx&&enemyQueue.front()->bullte.aimy + 1 == aimy))
					{
						enemyQueue.front()->bullte.bullet = false;
					}
					else
					{
						enemyQueue.push(enemyQueue.front());
						enemyQueue.pop();
					}
				}

				if ((player_tank1.bullte.aimx == aimx&&player_tank1.bullte.aimy == aimy) || (player_tank1.bullte.aimx == aimx&&player_tank1.bullte.aimy + 1 == aimy))
				{
					player_tank1.bullte.bullet = false;
				}

				if ((player_tank2.bullte.aimx == aimx&&player_tank2.bullte.aimy == aimy) || (player_tank2.bullte.aimx == aimx&&player_tank2.bullte.aimy + 1 == aimy))
				{
					player_tank2.bullte.bullet = false;
				}
			}
		}
		break;
	default:
		break;
	}
}

void bulltes::BulletHit_bullte(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int playerlife[])
{
	switch (direct)
	{
	case Up:
	case Down:
		if (bulletmap[aimx][aimy] == 1 || bulletmap[aimx + 1][aimy] == 1)
		{
			if ((player_tank1.bullte.aimx == aimx&&player_tank1.bullte.aimy == aimy) || (player_tank1.bullte.aimx + 1 == aimx&&player_tank1.bullte.aimy == aimy))
			{
				player_tank1.bullte.bullet = false;
			}
			if ((player_tank1.bullte.aimx == aimx&&player_tank2.bullte.aimy == aimy) || (player_tank2.bullte.aimx + 1 == aimx&&player_tank2.bullte.aimy == aimy))
			{
				player_tank2.bullte.bullet = false;
			}
		}
		break;
	case Left:
	case Right:
		if (bulletmap[aimx][aimy] == 1 || bulletmap[aimx][aimy + 1] == 1)
		{


			if ((player_tank1.bullte.aimx == aimx&&player_tank1.bullte.aimy == aimy) || (player_tank1.bullte.aimx == aimx&&player_tank1.bullte.aimy + 1 == aimy))
			{
				player_tank1.bullte.bullet = false;
			}
			if ((player_tank2.bullte.aimx == aimx&&player_tank2.bullte.aimy == aimy) || (player_tank2.bullte.aimx == aimx&&player_tank2.bullte.aimy + 1 == aimy))
			{
				player_tank2.bullte.bullet = false;
			}

		}
		break;
	default:
		break;
	}
}

bool bulltes::Canfire()
{
	return !bullet;
}


bool bulltes::Canmove(map & map, int(*tankmap)[26], int(*bulltemap)[26], tank_player& player_tank, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int& playerlife, int& enemynum, int& score)
{
	if (bullet&&count == 0)
	{
		switch (direct)
		{
		case Up:
			if (aimy < 0)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx + 1, aimy) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx + 1, aimy) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx + 1, aimy) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulltemap[aimx][aimy - 1] == 1 || bulltemap[aimx + 1][aimy - 1] == 1)
			{
				aimy--;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}



			if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		case Down:
			if (aimy > 25)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx + 1, aimy) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx + 1, aimy) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx + 1, aimy) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulltemap[aimx][aimy + 1] == 1 || bulltemap[aimx + 1][aimy + 1] == 1)
			{
				aimy++;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		case Right:
			if (aimx > 25)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx, aimy + 1) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx, aimy + 1) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx, aimy + 1) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy + 1) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulltemap[aimx + 1][aimy] == 1 || bulltemap[aimx + 1][aimy + 1] == 1)
			{
				aimx++;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		case Left:
			if (aimx < 0)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx, aimy + 1) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx, aimy + 1) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx, aimy + 1) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy + 1) == home_h)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulltemap[aimx - 1][aimy] == 1 || bulltemap[aimx - 1][aimy + 1] == 1)
			{
				aimx--;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		}

		if (bullet == false)
		{
			if (state == lose)
				music.mu_Lose();
			return false;
		}
		return true;
	}
	return false;
}

bool bulltes::Canmove(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int & playerlife, int & enemynum, int & score)
{
	if (bullet&&count == 0)
	{
		switch (direct)
		{
		case Up:
			if (aimy < 0)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx + 1, aimy) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx + 1, aimy) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx + 1, aimy) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulletmap[aimx][aimy - 1] == 1 || bulletmap[aimx + 1][aimy - 1] == 1)
			{
				aimy--;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}



			if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		case Down:
			if (aimy > 25)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx + 1, aimy) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx + 1, aimy) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx + 1, aimy) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulletmap[aimx][aimy + 1] == 1 || bulletmap[aimx + 1][aimy + 1] == 1)
			{
				aimy++;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		case Right:
			if (aimx > 25)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx, aimy + 1) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx, aimy + 1) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx, aimy + 1) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy + 1) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulletmap[aimx + 1][aimy] == 1 || bulletmap[aimx + 1][aimy + 1] == 1)
			{
				aimx++;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		case Left:
			if (aimx < 0)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx, aimy + 1) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx, aimy + 1) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx, aimy + 1) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy + 1) == home_h)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				state = lose;
				bullet = false;

			}
			if (bulletmap[aimx - 1][aimy] == 1 || bulletmap[aimx - 1][aimy + 1] == 1)
			{
				aimx--;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score);
				bullet = false;
			}

			break;
		}

		if (bullet == false)
		{
			if (state == lose)
				music.mu_Lose();
			return false;
		}
		return true;
	}
	return false;
}

bool bulltes::Canmove(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int playerlife[])
{
	if (bullet&&count == 0)
	{
		switch (direct)
		{
		case Up:
			if (aimy < 0)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx + 1, aimy) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx + 1, aimy) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx + 1, aimy) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (bulletmap[aimx][aimy - 1] == 1 || bulletmap[aimx + 1][aimy - 1] == 1)
			{
				aimy--;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}



			if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			break;
		case Down:
			if (aimy > 25)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx + 1, aimy) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx + 1, aimy) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx + 1, aimy) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx + 1, aimy) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (bulletmap[aimx][aimy + 1] == 1 || bulletmap[aimx + 1][aimy + 1] == 1)
			{
				aimy++;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx + 1][aimy] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			break;
		case Right:
			if (aimx > 25)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx, aimy + 1) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx, aimy + 1) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx, aimy + 1) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy + 1) == home_h)
			{

				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (bulletmap[aimx + 1][aimy] == 1 || bulletmap[aimx + 1][aimy + 1] == 1)
			{
				aimx++;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			break;
		case Left:
			if (aimx < 0)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				bullet = false;
				break;
			}
			if (map.getmember(0, aimx, aimy) == stone || map.getmember(0, aimx, aimy + 1) == stone || map.getmember(0, aimx, aimy) == steel || map.getmember(0, aimx, aimy + 1) == steel)
			{
				music.mu_Hit_Wall();
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (map.getmember(1, aimx, aimy) == home || map.getmember(1, aimx, aimy + 1) == home || map.getmember(1, aimx, aimy) == home_h || map.getmember(1, aimx, aimy + 1) == home_h)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHit(map, state);
				bullet = false;

			}
			if (bulletmap[aimx - 1][aimy] == 1 || bulletmap[aimx - 1][aimy + 1] == 1)
			{
				aimx--;
				bombQueue.push(x - 10, y - 10);
				BulletHit_bullte(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			if (tankmap[aimx][aimy] == 1 || tankmap[aimx][aimy + 1] == 1)
			{
				bombQueue.push(x - 10, y - 10);
				BulletHitPlus(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife);
				bullet = false;
			}

			break;
		}

		if (bullet == false)
		{
			if (state == lose)
				music.mu_Lose();
			return false;
		}
		return true;
	}
	return false;
}

void bulltes::update_move(map & map, int(*tankmap)[26], int(*bulltemap)[26], tank_player& player_tank, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int& playerlife, int& enemynum, int& score)
{
	if (bullet&&Canmove(map, tankmap, bulltemap, player_tank, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score))
		switch (direct)
		{
		case Up:
			aimy--;
			break;
		case Down:
			aimy++;
			break;
		case Right:
			aimx++;
			break;
		case Left:
			aimx--;
			break;
		}
}

void bulltes::update_move(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, queue<tanke_enemy*>& enemyQueue, queue<tanke_enemy*>& deadenemyQueue, queue<prop*>& propertyQueue, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int & playerlife, int & enemynum, int & score)
{
	if (bullet&&Canmove(map, tankmap, bulletmap, player_tank1, player_tank2, enemyQueue, deadenemyQueue, propertyQueue, bombQueue, bornQueue, state, playerlife, enemynum, score))
		switch (direct)
		{
		case Up:
			aimy--;
			break;
		case Down:
			aimy++;
			break;
		case Right:
			aimx++;
			break;
		case Left:
			aimx--;
			break;
		}
}

void bulltes::update_move(map & map, int(*tankmap)[26], int(*bulletmap)[26], tank_player & player_tank1, tank_player & player_tank2, myQueue & bombQueue, myQueue & bornQueue, gameState & state, int playerlife[])
{
	if (bullet&&Canmove(map, tankmap, bulletmap, player_tank1, player_tank2, bombQueue, bornQueue, state, playerlife))
		switch (direct)
		{
		case Up:
			aimy--;
			break;
		case Down:
			aimy++;
			break;
		case Right:
			aimx++;
			break;
		case Left:
			aimx--;
			break;
		}
}

void bulltes::update_xy()
{

	if (count)
	{
		switch (direct)
		{
		case Up:
			y -= speed;
			break;
		case Down:
			y += speed;
			break;
		case Right:
			x += speed;
			break;
		case Left:
			x -= speed;
			break;
		}
		count--;
	}
	else
	{
		count = 20 / speed;
	}
}

void bulltes::creatProp(int x, int y, queue<prop*>& propertyQueue)
{
	int n = myrand_int(0, 500);
	if (0 < n&&n < 100)
	{
		music.mu_Prop_Appear();
		prop *p;

		if (n > 0 && n < 20)
		{
			p = new prop;
			p->pro = tank;
			p->time = 500;
			p->x = aimx;
			p->y = aimy;
			propertyQueue.push(p);
		}
		else if (n > 20 && n < 40)
		{
			p = new prop;
			p->pro = bomb;
			p->time = 500;
			p->x = aimx;
			p->y = aimy;
			propertyQueue.push(p);
		}
		else if (n > 40 && n < 60)
		{
			p = new prop;
			p->pro = star;
			p->time = 500;
			p->x = aimx;
			p->y = aimy;
			propertyQueue.push(p);
		}
		else if (n > 60 && n < 80)
		{
			p = new prop;
			p->pro = timer;
			p->time = 500;
			p->x = aimx;
			p->y = aimy;
			propertyQueue.push(p);
		}
		else if (n > 80 && n < 100)
		{
			p = new prop;
			p->pro = sheld;
			p->time = 500;
			p->x = aimx;
			p->y = aimy;
			propertyQueue.push(p);
		}
	}
}
