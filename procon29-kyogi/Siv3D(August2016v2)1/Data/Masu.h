#pragma once
class Masu {
public :
	//タイルのポイント
	int TilePoint;
	//Non-何もなし,FriendTile-味方のタイル,EnemyTile-敵のタイル
	//置かれているタイルを管理
	enum StateOfMasu{ Non = 0, FriendTile = 1, EnemyTile = 2 , Other = 3 };
	StateOfMasu Status;
private:
};

