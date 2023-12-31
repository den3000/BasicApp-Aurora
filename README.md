# Пример элемементарного приложения на Аврора ОС

В данном демо, созданном изначально для доклада на Omsk DevFest 2023, а потом улучшенном для Mobius Autumn 2023, на тривиальном примере (всего два экрана) рассматриваются следующие ключевые моменты:
1. Создание координатора, который будет управлять PageStack, и т.о. позволит отделить логику навигации от реализации экранов
2. Разделение каждого экрана на UI представление (QML) и ViewModel, которая создана на стороне C++, чтобы иметь возможность отделить бизнесс-логику экрана от его UI представления
3. Как сделать инджект ViewModel из С++ в QML и при этом не получить проблем с утечками памяти
4. Использование DIContainer и DIProvider для организации и использования DI в приложении

Данный код не являтеся прямым руководством к тому, как надо программировать на Аврора ОС с помощью C++/Qt. Это всего лишь попытка перенести подходы выработанные с годами Android и iOS разработчиками на новую платформу.

Релизы:
1. [Омск DevFest 2023](https://github.com/den3000/BasicApp-Aurora/releases/tag/omsk_dev_fest_2023_10_06) - тривиальное приложение с двумя экранами, координатором, вьюмоделями и тривиальными DI
2. [Mobius Autumn 2023 v1](https://github.com/den3000/BasicApp-Aurora/releases/tag/mobius_autumn_2023_no_di) - тривиальное приложение с двумя экранами, координатором, вьюмоделями, передача данных между экранами
3. [Mobius Autumn 2023 v2](https://github.com/den3000/BasicApp-Aurora/releases/tag/mobius_autumn_2023) - тоже самое, что и `Mobius Autumn 2023 v1`, но только с классом сервисом и DI
