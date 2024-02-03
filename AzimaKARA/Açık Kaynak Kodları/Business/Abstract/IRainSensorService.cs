using Entities.Concrete;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Abstract
{
    public interface IRainSensorService
    {
        void Add(RainSensoDto rainSensorDto);
        Task<List<RainSensor>> GetList();
        Task<RainSensor> GetEndData();

    }
}
