#include <cstring>

struct Soldier
{
    int version, mId;
    Soldier* next;
    Soldier(int version, int mId, Soldier* next) {
        this->version = version;
        this->mId = mId;
        this->next = next;
    }
};

int sVersion[100001];
int sTeam[100001];

struct team {
    Soldier* head;
    Soldier* tail;
}teams[6][6];


void init()
{
    memset(sVersion, 0, sizeof(sVersion));
    memset(sTeam, 0, sizeof(sTeam));
    memset(teams, 0, sizeof(teams));
}

void hire(int mID, int mTeam, int mScore)
{
    Soldier* ts = new Soldier(++sVersion[mID], mID, 0);

    sTeam[mID] = mTeam;

    team& myTeam = teams[mTeam][mScore];

    if (!myTeam.head) {
        myTeam.head = ts;
        myTeam.tail = ts;
    }
    else {
        myTeam.tail->next = ts;
        myTeam.tail = ts;
    }
}

void fire(int mID)
{
    sVersion[mID]++;
}

void updateSoldier(int mID, int mScore)
{
    Soldier* ts = new Soldier(++sVersion[mID], mID, 0);

    team& myTeam = teams[sTeam[mID]][mScore];

    if (!myTeam.head) {
        myTeam.head = ts;
        myTeam.tail = ts;
    }
    else {
        myTeam.tail->next = ts;
        myTeam.tail = ts;
    }
}

void updateTeam(int mTeam, int mChangeScore)
{
    if (mChangeScore < 0) {
        for (int i = 1; i < 6; i++) {
            if (!teams[mTeam][i].head) continue;
            int nScore = i + mChangeScore < 1 ? 1 : i + mChangeScore;
            Soldier* thead = teams[mTeam][i].head;
            Soldier* ttail = teams[mTeam][i].tail;
            
            teams[mTeam][i].head = 0;
            teams[mTeam][i].tail = 0;

            if (!teams[mTeam][nScore].tail) {
                teams[mTeam][nScore].head = thead;
                teams[mTeam][nScore].tail = ttail;
            }
            else {
                teams[mTeam][nScore].tail->next = thead;
                teams[mTeam][nScore].tail = ttail;
            }
        }
    }
    if (mChangeScore > 0) {
        for (int i = 5; i > 0; i--) {
            if (!teams[mTeam][i].head) continue;
            int nScore = i + mChangeScore > 5 ? 5 : i + mChangeScore;
            Soldier* thead = teams[mTeam][i].head;
            Soldier* ttail = teams[mTeam][i].tail;

            teams[mTeam][i].head = 0;
            teams[mTeam][i].tail = 0;

            if (!teams[mTeam][nScore].tail) {
                teams[mTeam][nScore].head = thead;
                teams[mTeam][nScore].tail = ttail;
            }
            else {
                teams[mTeam][nScore].tail->next = thead;
                teams[mTeam][nScore].tail = ttail;
            }
        }
    }
}

int bestSoldier(int mTeam)
{

    for (int i = 5; i > 0; i--) {
        int bestId = -1;

        Soldier* cur = teams[mTeam][i].head;
        while (cur) {
            int tmId = cur->mId;
            if (sVersion[tmId] == cur->version)
                bestId = bestId < tmId ? tmId : bestId;
            cur = cur->next;
        }
        if (bestId != -1) return bestId;
    }
    return 0;
}