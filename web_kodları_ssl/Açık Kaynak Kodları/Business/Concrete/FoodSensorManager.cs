using Business.Abstract;
using DataAccess.Abstract;
using Entities.Concrete;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class FoodSensorManager : IFoodSensorService
    {
        private readonly IFoodSensorDal _foodSensorDal;

        public FoodSensorManager(IFoodSensorDal foodSensorDal)
        {
            _foodSensorDal = foodSensorDal;
        }

        public void Add(FoodSensorDto foodSensorDto)
        {
            FoodSensor foodSensor = new FoodSensor();
            foodSensor.Distance = foodSensorDto.Distance;
            foodSensor.Date = DateTime.Now;
           _foodSensorDal.Insert(foodSensor);
        }

        public async Task<List<FoodSensor>> GetAll()
        {
           return await _foodSensorDal.GetList();
        }

        public async Task<FoodSensorDto> GetEndData()
        {
            var data = await _foodSensorDal.GetList();
            var endData = data.OrderByDescending(x => x.Id).FirstOrDefault();
            FoodSensorDto foodSensorDto = new FoodSensorDto();
            foodSensorDto.Distance = endData.Distance;

            return foodSensorDto;
        }
    }
}
