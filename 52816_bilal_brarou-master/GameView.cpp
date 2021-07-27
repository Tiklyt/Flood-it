#include "GameView.h"
GameView::GameView(Game &game, QWidget *parent)
    : QGraphicsView(parent), gameScene(new QGraphicsScene()), fm("0", "0"),
      gm(game) {
  plateView.resize(gm.getBoard().getLigne());
  for (unsigned short i = 0; i < gm.getBoard().getLigne(); ++i)
    plateView[i].resize(gm.getBoard().getCol());
  initialize();
  initializeButton();
  drawBoard();
}

void GameView::initialize() {
  gameScene->setSceneRect(0, 0, 900, 700);
  title = gameScene->addText("flood-it !", QFont("Comic Sans MS", 35));
  movesText = gameScene->addText("moves : 0", QFont("Comic Sans MS", 25));
  movesText->setPos(625, 100);
  title->setPos(200, 0);
  title->setDefaultTextColor(QColor(252, 194, 3));
  winMsg = gameScene->addText("YOU WIN !", QFont("Comic Sans MS", 25));
  winMsg->setPos(625, 200);
  winMsg->hide();
  // std::string value = "best moves : " + std::to_string(fm.getScore());
  lastNbMoves =
      gameScene->addText("best moves : 0", QFont("Comic Sans MS", 25));
  lastNbMoves->setPos(625, 150);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setScene(gameScene);
  setFixedSize(900, 700);
  setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
}

void GameView::initializeButton() {
  bSize = new QComboBox;
  bSize->addItem("5x5");
  bSize->addItem("10x10");
  bSize->addItem("20x10");
  bSize->addItem("30x15");
  bSize->move(60, 620);
  gameScene->addWidget(bSize);
  nbColors = new QComboBox;
  nbColors->addItem("5 colors");
  nbColors->addItem("8 Colors");
  nbColors->addItem("10 Colors");
  nbColors->move(130, 620);
  gameScene->addWidget(nbColors);
  start = new QPushButton;
  start->setText("START");
  start->move(220, 620);
  gameScene->addWidget(start);
  connect(start, &QPushButton::clicked, [=] {
    gm.resetNbMove();
    std::string toPrint = "moves  : " + std::to_string(gm.getNbMoves());
    movesText->setPlainText(toPrint.c_str());
    winMsg->hide();
    switch (bSize->currentIndex()) {
    case 0:
      resizeTo(5, 5);
      break;
    case 1:
      resizeTo(10, 10);
      break;
    case 2:
      resizeTo(20, 10);
      break;
    case 3:
      resizeTo(30, 15);
      break;
    }
    switch (nbColors->currentIndex()) {
    case 0:
      gm.setNbColors(4);
      break;
    case 1:
      gm.setNbColors(8);
      break;
    case 2:
      gm.setNbColors(10);
      break;
    }
  });
}

void GameView::initialize_connection() {
  for (unsigned i = 0; i < plateView.size(); i++) {
    for (unsigned j = 0; j < plateView[0].size(); j++) {
      connect(plateView[i][j], &CellView::clicked, [=] {
        gm.colorChanger(0, 0, gm.getBoard().getPlate()[0][0]->getColor(),
                        plateView[i][j]->getCell().getColor());
        if (!gm.hasWon()) {
          gm.incNbMove();
        } else {
          // unsigned val = fm.getScore();
          // fm.writeScore(val);
          winMsg->show();
        }
        std::string toPrint = "moves  : " + std::to_string(gm.getNbMoves());
        movesText->setPlainText(toPrint.c_str());
        movesText->hide();
        movesText->show();
      });
    }
  }
}

void GameView::drawBoard() {
  unsigned short maxSize = sizeRect / gm.getBoard().getLigne();
  srand(time(0));
  for (size_t i = 0; i < gm.getBoard().getLigne(); i++) {
    for (size_t j = 0; j < gm.getBoard().getCol(); j++) {
      plateView[i][j] = new CellView(gm.getBoard().getPlate()[i][j]);
      plateView[i][j]->setRect(0, 0, sizeRect / gm.getBoard().getLigne(),
                               maxSize);
      plateView[i][j]->setPos(maxSize * i + 60, maxSize * j + 100);
      gameScene->addItem(plateView[i][j]);
    }
  }
  gm.randomize();
  initialize_connection();
}

GameView::~GameView() {
  for (unsigned i = 0; i < plateView.size(); i++) {
    for (unsigned j = 0; j < plateView[0].size(); j++) {
      delete plateView[i][j];
      plateView[i][j] = nullptr;
    }
  }
}

void GameView::resizeTo(int x, int y) {
  gm.getBoard().resizeTo(x, y);
  for (unsigned i = 0; i < plateView.size(); i++) {
    for (unsigned j = 0; j < plateView[0].size(); j++) {
      delete plateView[i][j];
    }
  }
  plateView.resize(x);
  for (int i = 0; i < x; i++) {
    plateView[i].resize(y);
  }
  drawBoard();
}
