#include <QtTest>


// add necessary includes here
#include "../../Game/core/statistics.hh"

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();
    ~StatisticsTest();

private slots:
    void getPoints();
    void addPoints();

private:
    Game::Statistics stats;
};

StatisticsTest::StatisticsTest()
{
    stats = Game::Statistics();
}

StatisticsTest::~StatisticsTest()
{

}

void StatisticsTest::getPoints()
{
    QVERIFY(stats.getPoints() == 0);
}

void StatisticsTest::addPoints()
{
    stats.addPoints(5);
    QVERIFY(stats.getPoints() == 5);
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "tst_statistics.moc"
