#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct bazikon {
	char name[30];
	int price;
	int speed;
	int finishing;
	int defence;
	int team;//this player is in which team(team's id)
};

struct team {
	char name[30];
	int money;
	int bazikon[40];//is an array for sorting id player based on join the team
	int tedad_bazikon;//how many player dose this team have?
	int win;
	int lose;
};
//---------------------------------------------------------------------------------------------------------
void buy(struct bazikon bazikon[1100], struct team team[100], int id_bazikon, int id_team) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > id_bazikon) {
		printf("player with the id %d doesnt exist\n", a);
		return;
	}
	else if (b > id_team) {
		printf("team with the id %d doesnt exist\n", b);
		return;
	}
	else if (team[b].money < bazikon[a].price) {
		printf("the team cant afford to buy this player\n");
		return;
	}
	else if (bazikon[a].team != 0) {
		printf("player already has a team\n");
		return;
	}
	else {
		printf("player added to the team succesfully\n");
		int c = team[b].tedad_bazikon;
		team[b].bazikon[c + 1] = a;
		bazikon[a].team = b;
		team[b].money -= bazikon[a].price;
		team[b].tedad_bazikon++;
		return;
	}
}

void sell(struct bazikon bazikon[1100], struct team team[100], int id_bazikon, int id_team) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (b > id_team) {
		printf("team doesnt exist\n");
		return;
	}
	else if (b != bazikon[a].team) {
		printf("team doesnt have this player\n");
		return;
	}
	else {
		printf("player sold succesfully\n");
		for (int i = a; i < team[b].tedad_bazikon; i++) {
			team[b].bazikon[i] = team[b].bazikon[i + 1];
		}
		team[b].bazikon[team[b].tedad_bazikon] = 0;
		team[b].tedad_bazikon--;
		team[b].money += bazikon[a].price;
		bazikon[a].team = 0;
		return;
	}
}

void match(struct bazikon bazikon[1100], struct team team[100], int id_team1, int id_team2, int id_team) {
	if (id_team < id_team1 || id_team < id_team2) {
		printf("team doesnt exist\n");
		return;
	}
	else if (team[id_team1].bazikon[11] == 0 || team[id_team2].bazikon[11] == 0) {
		printf("the game can not be held due to loss of the players\n");
		return;
	}
	int ghodrat1 = 0, ghodrat2 = 0;
	int c;
	for (int i = 1; i <= 11; i++) {
		c = team[id_team1].bazikon[i];
		ghodrat1 += (bazikon[c].speed + bazikon[c].finishing);
	}
	for (int i = 1; i <= 11; i++) {
		c = team[id_team2].bazikon[i];
		ghodrat2 += (bazikon[c].speed + bazikon[c].defence);
	}
	if (ghodrat1 > ghodrat2) {
		team[id_team1].win++;
		team[id_team2].lose++;
		team[id_team1].money += 1000;
	}
	else if (ghodrat2 > ghodrat1) {
		team[id_team1].lose++;
		team[id_team2].win++;
		team[id_team2].money += 1000;
	}
}

void chart(struct team jadval[100], int id_team) {
	for (int i = 1; i <= id_team; i++) {
		for (int j = i + 1; j <= id_team; j++) {
			if (jadval[j].win > jadval[i].win) {
				struct team temp;
				temp = jadval[i];
				jadval[i] = jadval[j];
				jadval[j] = temp;
			}
			else if (jadval[j].win == jadval[i].win) {
				if (jadval[j].lose < jadval[i].lose) {
					struct team temp;
					temp = jadval[i];
					jadval[i] = jadval[j];
					jadval[j] = temp;
				}
			}
		}
	}
	for (int i = 1; i <= id_team; i++) {
		printf("%d. %s\n", i, jadval[i].name);
	}
}
int main() {
	struct bazikon bazikon[1100] = {};
	struct team team[100] = {};
	int id_bazikon = 0, id_team = 0;
	char a[10];
	while (1) {
		scanf("%s", a);
		if (strcmp(a, "end") == 0) break;
		else if (strcmp(a, "new") == 0) {
			scanf("%s", a);
			if (strcmp(a, "player") == 0) {
				id_bazikon++;
				scanf("%s %d %d %d %d", bazikon[id_bazikon].name, &bazikon[id_bazikon].price, &bazikon[id_bazikon].speed, &bazikon[id_bazikon].finishing, &bazikon[id_bazikon].defence);
				bazikon[id_bazikon].team = 0;
			}
			else if (strcmp(a, "team") == 0) {
				id_team++;
				scanf("%s %d", team[id_team].name, &team[id_team].money);
				team[id_team].tedad_bazikon = team[id_team].win = team[id_team].lose = 0;
				for (int u = 1; u < id_team; u++) {
					if (strcmp(team[u].name, team[id_team].name) == 0) {
						id_team--;
						break;
					}
				}
			}
		}
		else if (strcmp(a, "buy") == 0) {
			buy(bazikon, team, id_bazikon, id_team);
		}
		else if (strcmp(a, "sell") == 0) {
			sell(bazikon, team, id_bazikon, id_team);
		}
		else if (strcmp(a, "match") == 0) {
			int m, n;
			scanf("%d %d", &m, &n);
			match(bazikon, team, m, n, id_team);
		}
		else if (strcmp(a, "rank") == 0) {
			struct team jadval[100];
			for (int i = 1; i <= id_team; i++) {
				jadval[i] = team[i];
			}
			chart(jadval, id_team);
		}
	}
}