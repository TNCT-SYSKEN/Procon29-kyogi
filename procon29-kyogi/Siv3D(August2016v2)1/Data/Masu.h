#pragma once
class Masu {
public :
	static Masu* getMasu();
	//タイルのポイント
	int TilePoint;
	//Non-何もなし,FriendTile-味方のタイル,EnemyTile-敵のタイル
	//置かれているタイルを管理
	enum StateOfMasu{ Non = 0, FriendTile = 1, EnemyTile = 2 };
	StateOfMasu State;
private:
	static Masu* InsMasu;
};


