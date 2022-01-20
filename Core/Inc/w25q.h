#ifndef _W25Q_H
#define _W25Q_H

// Порт SPI (При необходимости изменить на нужный)
extern SPI_HandleTypeDef        hspi1;
#define W25Q_SPI                &hspi1

// Пустышка
#define W25Q_SPI_NOP            0xFF

// Порт на котором подключен CS
#define W25Q_PORT     GPIOB

// Пин на котором подключен CS
#define W25Q_PIN      GPIO_PIN_2

// Вывод CS в 0
#define W25Q_CS_LO() HAL_GPIO_WritePin(W25Q_PORT, W25Q_PIN, GPIO_PIN_RESET);
// Вывод CS в 1
#define W25Q_CS_HI() HAL_GPIO_WritePin(W25Q_PORT, W25Q_PIN, GPIO_PIN_SET);


// Объем памяти микросхемы
#define W25Q_MAMORY_8           0x4014 // 1МБ
#define W25Q_MAMORY_16          0x4015 // 2МБ
#define W25Q_MAMORY_32          0x4016 // 4МБ

// Фирма производитель
#define W25Q_WINBOND            0xEF // Winbond

// Размер страницы
#define W25Q_PAGE_LEN           256

// Размер сектора в КБ
#define W25Q_SECTOR_4           0x04

// Размер блока в КБ
#define W25Q_BLOCK_64           0x40

// Количество страниц
#define W25Q_PAGE_8             0x0FFF
#define W25Q_PAGE_16            0x1FFF
#define W25Q_PAGE_32            0x3FFF


// Команды
#define W25Q_WRITE_ENABLE       0X06
#define W25Q_WRRITE_DISABLE     0X04
#define W25Q_RD_STATUS_1        0x05       
#define W25Q_RD_STATUS_2        0x35
#define W25Q_WR_STATUS          0x01
#define W25Q_PAGE_PROGRAM       0x02
#define W25Q_Q_PAGE_PROGRAM     0x32
#define W25Q_BLOCK_ERASE_64     0xD8
#define W25Q_BLOCK_ERASE_32     0x52
#define W25Q_SECTOR_ERASE_4     0x20
#define W25Q_CHIP_ERASE         0xC7
#define W25Q_ERASE_SUSPEND      0X75
#define W25Q_ERASE_RESUME       0x7A
#define W25Q_POWER_DOWN         0xB9
#define W25Q_HI_PF_MODE         0xA3
#define W25Q_MODE_BIT_RESET     0xFF
#define W25Q_RS_PWR_DOUN        0xAB
#define W25Q_MNF_DEVICE_ID      0x90
#define W25Q_RD_UNIQUE_ID       0x4B
#define W25Q_JEDEC_ID           0x9F
#define W25Q_READ_PAGE          0x0B

// Чтение статусного регистра
void w25qReadStatus(uint8_t *answer, uint8_t regnum);

// Ожидание сброса бита занятости
void w25qWaitForReady(void);

// Установка защитных бит
void w25qSetBlockProtect(uint8_t protect);

// Чтение сигнатуры. 
// В качестве аргумента принимает массив на 3 ячейки
// После вызова функции в массиве будут:
//      answer[0] = индекс производителя
//      answer[1] = старший байт объема памяти
//      answer[2] = младший байт объема памяти
// Пример: 0xEF, 0x40, 0x16 = W25Q32
void w25qReadManuf(uint8_t *answer);

// Чтение страницы
// В качестве аргумента принимает массив на 
// 256 ячеек и номер страницы для чтения
// После вызова функции в массиве будет лежать прочитанная страница
void w25qReadPage(uint8_t *page, uint16_t pagenum);

// Запись страницы
// В качестве аргумента принимает массив с данными на 
// 256 ячеек и номер страницы для записи
void w25qWritePage(uint8_t *page, uint16_t pagenum);

// Очистка сектора 4КБ
void w25qEraseSector(uint16_t sector);

// Стереть всю память
void w25qEraseChip(void);

#endif /* _W25Q_H */
