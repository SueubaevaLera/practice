<<<<<<< HEAD
=======

>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
#include <iostream>
#include <opencv2/opencv.hpp>
#include <ViZDoom.h>
#include <thread>
#include <Chrono>

std::string path = "C:/practice/vizdoom";
auto game = std::make_unique<vizdoom::DoomGame>();
const unsigned int sleepTime = 1000 / vizdoom::DEFAULT_TICRATE;
auto screenBuff = cv::Mat(480, 640, CV_8UC3);
const char* filename = "./sprites/Enemies/heada1.png";
const char* filename1 = "./sprites/Enemies/heada2a8.png";
<<<<<<< HEAD
const char* med = "./sprites/Pickups/media0.png";
std::vector<std::vector<double>> action = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
const char* h2so4a = "./sprites/Pickups/bon1a0.png";
const char* h2so4b = "./sprites/Pickups/bon1b0.png";
const char* h2so4c = "./sprites/Pickups/bon1c0.png";
const char* h2so4d = "./sprites/Pickups/bon1d0.png";
int total = 0;

=======
std::vector<std::vector<double>> action = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
int total = 0;

//две новые операции для задания 2:

>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
int leng(int x1, int y1, int x2, int y2) {
    double leng = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return int(leng);
}

double angleE(double line1, double line2, double opLine) {
    double cosAn = (pow(line1, 2) + pow(line2, 2) - pow(opLine, 2)) / (2 * line1 * line2);
    double angle = acos(cosAn) * 180 / 3.14;

    return angle;
}



void RunTask1(int episodes) {
    try {
        game->loadConfig(path + "/scenarios/task1.cfg");
        game->init();
    }

    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    auto greyscale = cv::Mat(480, 640, CV_8UC1);

    std::vector<double> action;

    for (auto i = 0; i < episodes; i++) {
        game->newEpisode();

        std::cout << "Episode #" << i + 1 << std::endl;

        int x = 1;

<<<<<<< HEAD
        cv::Mat img = screenBuff;

        while (!game->isEpisodeFinished()) {
            const auto& gamestate = game->getState();

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size());

            cv::extractChannel(screenBuff, greyscale, 2);
            cv::threshold(greyscale, greyscale, 200, 255, cv::THRESH_BINARY);

            for (int c = 0; c < 640; c++) {
                if ((int)greyscale.at<uchar>(cv::Point(c, 239)) == 255) {
=======
        cv::Mat img = screenBuff; 

        while (!game->isEpisodeFinished()) {
            const auto& gamestate = game->getState(); 

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size()); 

            cv::extractChannel(screenBuff, greyscale, 2);
            cv::threshold(greyscale, greyscale, 200, 255, cv::THRESH_BINARY); 

            for (int c = 0; c < 640; c++) {
                if ((int)greyscale.at<uchar>(cv::Point(c, 245)) == 255) {
>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
                    x = c;
                }
            }

            if (x > 300 && x < 340) {
                double reward = game->makeAction({ 0,0,1 });
            }
            if (x <= 300) {
                game->makeAction({ 1,0,0 });
            }
            else {
                game->makeAction({ 0,1,0 });
            }

            cv::imshow("Output Window", img);
            cv::waitKey(sleepTime);
        }

<<<<<<< HEAD
        total = total + game->getTotalReward();
=======
        int total = game->getTotalReward();
>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9

        std::cout << std::endl << game->getTotalReward() << std::endl;
    }
    std::cout << std::endl << double(total) / episodes;
}

void RunTask2(int episodes) {
    try {
        game->loadConfig(path + "/scenarios/task2.cfg");
        game->init();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    auto greyscale = cv::Mat(480, 640, CV_8UC1);

    for (auto i = 0; i < episodes; i++) {
        game->newEpisode();

        std::cout << "Episode #" << i + 1 << std::endl;

        while (!game->isEpisodeFinished()) {
            const auto& gamestate = game->getState();

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size());

            cv::Mat img = screenBuff;
            cv::Mat temp1 = cv::imread(filename);
            cv::Mat temp2 = cv::imread(filename1);
            cv::Mat result;

<<<<<<< HEAD
            double minval;
            double maxval;
            cv::Point minLoc;
            cv::Point maxLoc;

            if (i == 4) {
=======
            double minval; double maxval; cv::Point minLoc; cv::Point maxLoc;

            if(i==4){
>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
                int result_cols = img.cols - temp2.cols + 1;
                int result_rows = img.rows - temp2.rows + 1;

                result.create(result_rows, result_cols, CV_32FC1);

                matchTemplate(img, temp2, result, 4);

                normalize(result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

                minMaxLoc(result, &minval, &maxval, &minLoc, &maxLoc, cv::Mat());

                // rectangle(img, maxLoc, cv::Point(maxLoc.x + temp1.cols, maxLoc.y + temp1.rows), cv::Scalar::all(0), 2, 8, 0);

                double line1 = leng(maxLoc.x + temp2.cols / 2, maxLoc.y + temp2.rows / 2, 320, 479);
                double line2 = 480.0;
                double line3 = leng(maxLoc.x + temp2.cols / 2, maxLoc.y + temp2.rows / 2, 320, 0);
                double angle = angleE(line1, line2, line3);

                cv::imshow("Output Window", img);

                if (maxLoc.y < 240) {
                    if (angle < 5.0) game->makeAction({ 0, 0, 0, 1 });
                    else if (maxLoc.x + temp2.cols / 2 < 310) game->makeAction({ 1, 0, 0, 0 });
                    else if (maxLoc.x + temp2.cols / 2 > 360) game->makeAction({ 0, 1, 0, 0 });
                }
                else {
<<<<<<< HEAD
                    game->makeAction({ 0, 1, 0, 0 });
                    game->makeAction({ 0, 0, 0, 1 });
=======
                        game->makeAction({ 0, 1, 0, 0 });
                        game->makeAction({ 0, 0, 0, 1 });
>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
                }

                cv::waitKey(sleepTime);
            }
            else {
                int result_cols = img.cols - temp1.cols + 1;
                int result_rows = img.rows - temp1.rows + 1;

                result.create(result_rows, result_cols, CV_32FC1);

                matchTemplate(img, temp1, result, 4);

                normalize(result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

                minMaxLoc(result, &minval, &maxval, &minLoc, &maxLoc, cv::Mat());

                double line1 = leng(maxLoc.x + temp1.cols / 2, maxLoc.y + temp1.rows / 2, 320, 479);
                double line2 = 480.0;
                double line3 = leng(maxLoc.x + temp1.cols / 2, maxLoc.y + temp1.rows / 2, 320, 0);
                double angle = angleE(line1, line2, line3);

                cv::imshow("Output Window", img);

                if (maxLoc.y < 240) {
                    if (angle < 5.0) game->makeAction({ 0, 0, 0, 1 });
                    else if (maxLoc.x + temp1.cols / 2 < 310) game->makeAction(action[0]);
                    else if (maxLoc.x + temp1.cols / 2 > 330) game->makeAction(action[1]);
                }
                else game->makeAction({ 0, 0, 0, 1 });

                cv::waitKey(sleepTime);
            }
        }

        total = total + game->getTotalReward();

        std::cout << std::endl << game->getTotalReward() << std::endl;
    }
<<<<<<< HEAD

=======
    
>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
    std::cout << std::endl << double(total) / episodes;
}

void RunTask3(int episodes) {
<<<<<<< HEAD
    try
    {
        game->loadConfig(path + "/scenarios/task3.cfg");
        game->init();
    }

    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    for (auto i = 0; i < episodes; i++)
    {
        game->newEpisode();
        std::cout << "Episode #" << i + 1 << std::endl;

        while (!game->isEpisodeFinished())
        {
            const auto& gamestate = game->getState();

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size());

            cv::Mat img = screenBuff;
            cv::Mat medi = cv::imread(med);
            cv::Mat result;

            double minval, maxval; cv::Point minLoc, maxLoc;
            int res_cols = img.cols - medi.cols + 1;
            int res_rows = img.rows - medi.rows + 1;
            result.create(res_cols, res_rows, CV_32FC1);

            cv::matchTemplate(img, medi, result, 4);
            cv::normalize(result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
            cv::Rect roi(290, 0, 60, result.rows);
            result = result(roi);
            cv::minMaxLoc(result, &minval, &maxval, &minLoc, &maxLoc);

            if (maxLoc.y < 390) {
                if (290 + maxLoc.x < 300) game->makeAction({ 1, 0, 0, 1 });
                else if (290 + maxLoc.x > 340) game->makeAction({ 0, 1, 0, 1 });
                else game->makeAction({ 0, 0, 0, 1 });
            }
            else game->makeAction({ 1, 0, 0, 1 });

            cv::imshow("Output Window", img);
            cv::waitKey(sleepTime);

        }
        total = total + game->getEpisodeTime();
        std::cout << std::endl << game->getEpisodeTime() << std::endl;

    }
    std::cout << std::endl << double(total) / episodes;
}

void RunTask4(int episodes) {
    try
    {
        game->loadConfig(path + "/scenarios/task4.cfg");
        game->init();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    for (auto i = 0; i < episodes; i++)
    {
        game->newEpisode();
        std::cout << "Episode #" << i + 1 << std::endl;

        while (!game->isEpisodeFinished())
        {
            const auto& gamestate = game->getState();

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size());

            cv::Mat img = screenBuff;
            cv::Mat medi = cv::imread(med);
            cv::Mat result;

            double minval, maxval;
            cv::Point minLoc, maxLoc;
            int res_cols = img.cols - medi.cols + 1;
            int res_rows = img.rows - medi.rows + 1;
            result.create(res_cols, res_rows, CV_32FC1);

            cv::matchTemplate(img, medi, result, 4);
            cv::normalize(result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
            cv::Rect roi(260, 0, 120, result.rows - 50);
            result = result(roi);
            cv::minMaxLoc(result, &minval, &maxval, &minLoc, &maxLoc);


            if (maxLoc.y < 400) {
                if (290 + maxLoc.x < 300) game->makeAction({ 1, 0, 0, 0 });
                else if (290 + maxLoc.x > 340) game->makeAction({ 0, 1, 0, 0 });
                else game->makeAction({ 0, 0, 0, 1 });
            }
            else for (int k = 0; k < 6; k++) game->makeAction({ 1, 0, 0, 0 });


            cv::imshow("Output Window", img);
            cv::waitKey(sleepTime);

        }
        total = total + game->getEpisodeTime();
        std::cout << std::endl << game->getEpisodeTime() << std::endl;
    }
    std::cout << std::endl << double(total) / episodes;
}


void RunTask5(int episodes) {
    try
    {
        game->loadConfig(path + "/scenarios/task5.cfg");
        game->init();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    auto greyscale = cv::Mat(480, 640, CV_8UC1);

    for (auto i = 0; i < episodes; i++)
    {
        game->newEpisode();
        std::cout << "Episode #" << i + 1 << std::endl;

        cv::Mat img = screenBuff;

        while (!game->isEpisodeFinished()) {
            const auto& gamestate = game->getState();

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size());

            cv::extractChannel(screenBuff, greyscale, 2);

            cv::threshold(greyscale, greyscale, 200, 255, CV_THRESH_BINARY);


            int x = -1;
            for (int c = 50; c < 590; c++) {
                if ((int)greyscale.at<uchar>(cv::Point(c, 233)) == 255) {
                    x = c;
                }
            }


            if (x != -1) {
                if (x <= 320) game->makeAction({ 0,1,0 });
                if (x > 320) game->makeAction({ 1,0,0 });
            }
            else game->makeAction({ 0 });


            cv::imshow("Output Window", img);
            cv::imshow("Grey", greyscale);
            cv::waitKey(sleepTime);
        }

        total = total + game->getEpisodeTime();

        std::cout << std::endl << game->getEpisodeTime() << std::endl;
    }
    std::cout << std::endl << double(total) / episodes;
}

void RunTask6(int episodes) {
    try
    {
        game->loadConfig(path + "/scenarios/task6.cfg");
        game->init();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    auto greyscale = cv::Mat(480, 640, CV_8UC1);

    for (auto i = 0; i < episodes; i++)
    {
        game->newEpisode();
        std::cout << "Episode #" << i + 1 << std::endl;

        cv::Mat img = screenBuff;

        while (!game->isEpisodeFinished()) {
            const auto& gamestate = game->getState();

            std::memcpy(screenBuff.data, gamestate->screenBuffer->data(), gamestate->screenBuffer->size());

            cv::extractChannel(screenBuff, greyscale, 2);

            cv::threshold(greyscale, greyscale, 200, 255, CV_THRESH_BINARY);


            int x = -1;
            for (int c = 50; c < 590; c++) {
                if ((int)greyscale.at<uchar>(cv::Point(c, 233)) == 255) {
                    x = c;
                }
            }


            if (x != -1) {
                if (x <= 320) game->makeAction({ 0,1,0 });
                if (x > 320) game->makeAction({ 1,0,0 });
            }
            else game->makeAction({ 0 });


            cv::imshow("Output Window", img);
            cv::imshow("Grey", greyscale);
            cv::waitKey(sleepTime);
        }

        total = total + game->getEpisodeTime();

        std::cout << std::endl << game->getEpisodeTime() << std::endl;
    }
    std::cout << std::endl << double(total) / episodes;
}


=======

}

void RunTask4(int episodes) {

}

void RunTask5(int episodes) {

}

>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9
int main()
{
    game->setViZDoomPath(path + "/vizdoom.exe");
    game->setDoomGamePath(path + "/freedoom2.wad");

    cv::namedWindow("Output Window", cv::WINDOW_AUTOSIZE);

    auto episodes = 10;

<<<<<<< HEAD
    RunTask4(episodes);
=======
    RunTask2(episodes);
>>>>>>> 7437a72c48b001d50aa725ec024e69768a4b7ac9

    game->close();
}