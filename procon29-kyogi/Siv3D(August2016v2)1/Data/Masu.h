#pragma once
class Masu {
public :
	//�^�C���̃|�C���g
	int TilePoint;
	//Non-�����Ȃ�,FriendTile-�����̃^�C��,EnemyTile-�G�̃^�C��
	//�u����Ă���^�C�����Ǘ�
	enum StateOfMasu{ Non = 0, FriendTile = 1, EnemyTile = 2 , Other = 3 };
	StateOfMasu Status;
private:
};

