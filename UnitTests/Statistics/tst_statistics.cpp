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
    void maxPoints();
    void isWon();
    void nysses();
    void passengers();
    void customers();
    void reset();

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
    QVERIFY2(stats.getPoints() == 0, "getPoints() should return 0 after"
                                     " initialization");
}

void StatisticsTest::addPoints()
{
    stats.addPoints(5);
    QVERIFY2(stats.getPoints() == 5, "getPoints() should return 5 after"
                                     " addpoint(5) is called");
}

void StatisticsTest::maxPoints(){
    stats.setPointGoal("Easy");
    int pointGoalEasy = stats.getMaxPoints();
    QVERIFY2(pointGoalEasy > 0, "Point goal is set under zero when difficulty"
                                " is easy");

    stats.setPointGoal("Medium");
    int pointGoalMedium = stats.getMaxPoints();
    QVERIFY2(pointGoalMedium > pointGoalEasy, "Point goal is set under easy "
                                              "when difficulty is medium");

    stats.setPointGoal("Hard");
    int pointGoalHard = stats.getMaxPoints();
    QVERIFY2(pointGoalHard > pointGoalMedium, "Point goal is set under medium"
                                              " when difficulty is hard");
}

void StatisticsTest::isWon()
{
    stats.setPointGoal("Easy");

    QVERIFY2(!stats.isWon(), "Should return false if point goal is not reached "
                             "(difficulty: easy, points: 0");

    stats.addPoints(300);
    QVERIFY2(stats.isWon(), "Should return true when point goal is reached "
                            "(difficulty: easy, points: 300)");

}

void StatisticsTest::nysses()
{
    for(int i = 0; i < 15; i++){
        stats.newNysse();
    }
    QVERIFY2(stats.getBuses() == 15, "getBuses() should return 15 when newNysse"
                                     " is called 15 times");

    for(int i = 0; i < 15; i++){
        stats.nysseLeft();
    }
    QVERIFY2(stats.getBuses() == 0, "getBuses() should return 0 when nysseleft "
                                    "is called as many times as newNysse");
}

void StatisticsTest::passengers()
{
    for(int i = 0; i < 15; i++){
        stats.morePassengers(1);
    }
    QVERIFY2(stats.getPassengers() == 15, "getPassengers() should return 15 "
                                          "when morePassengers(1) is called 15 "
                                          "times");

    for(int i = 0; i < 15; i++){
        stats.lessPassenger(1);
    }

    for(int i = 0; i < 15; i++){
        stats.morePassengers(5);
    }
    QVERIFY2(stats.getPassengers() == 75, "getPassengers() should return 75 when"
                                          " morePassengers(5) is called 15 times");

    for(int i = 0; i < 15; i++){
        stats.lessPassenger(5);
    }
    QVERIFY2(stats.getPassengers() == 0, "getPassengers() should return 0 when "
                                         "lessPassengers(5) is called 15 times");
    qDebug() << stats.getPoints();
}

void StatisticsTest::customers()
{
    for(int i = 0; i < 15; i++){
        stats.newCustomer();
    }
    QVERIFY2(stats.getCustomers() == 15, "getCustomers() should return 15 when"
                                         " newCustomer(0) is called 15 times"
                                         " (initial value 0)");

    for(int i = 0; i < 15; i++){
        stats.fedCustomer();
    }
    QVERIFY2(stats.getCustomers() == 0, "getCustomers() should return 15 when"
                                         " fedCustomer(0) is called 15 times "
                                         "(if newCustomer test does not pass"
                                         " this fails also)");

}

void StatisticsTest::reset(){
    stats.reset();
    QVERIFY(stats.getBuses() == 0);
    QVERIFY(stats.getCustomers() == 0);
    QVERIFY(stats.getMaxPoints() == 0);
    QVERIFY(stats.getPassengers() == 0);
    QVERIFY(stats.getPoints() == 0);
}



QTEST_APPLESS_MAIN(StatisticsTest)

#include "tst_statistics.moc"
