/******** guard */

typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESRVED;
}DMA_CHANNEL;

typedef struct 
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_CHANNEL Channel[7];
}DMA_t;

#define DMA   ((volatile DMA_t *) 0x40020000)
